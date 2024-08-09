#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/signal_set.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

namespace beast = boost::beast;
namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

// Handles an HTTP request
class http_session : public std::enable_shared_from_this<http_session>
{
public:
    http_session(tcp::socket socket) : socket_(std::move(socket)) {}

    void start()
    {
        do_read();
    }

private:
    void do_read()
    {
        auto self = shared_from_this();
        http::async_read(socket_, buffer_, request_,
                         [self](beast::error_code ec, std::size_t)
                         {
                             if (!ec)
                             {
                                 self->handle_request();
                             }
                         });
    }

    void handle_request()
    {
        auto self = shared_from_this();
        http::response<http::string_body> res{http::status::ok, request_.version()};
        res.set(http::field::server, "Boost.Beast");
        res.set(http::field::content_type, "text/plain");
        res.keep_alive(request_.keep_alive());
        res.body() = "Hello, world!";
        res.prepare_payload();
        http::async_write(socket_, res,
                          [self](beast::error_code ec, std::size_t)
                          {
                              if (!ec)
                              {
                                  self->socket_.shutdown(tcp::socket::shutdown_send, ec);
                              }
                          });
    }

    tcp::socket socket_;
    beast::flat_buffer buffer_;
    http::request<http::string_body> request_;
};

// Accepts incoming connections
class listener : public std::enable_shared_from_this<listener>
{
public:
    listener(net::io_context &ioc, tcp::acceptor &acceptor) : ioc_(ioc), acceptor_(acceptor) {}

    void start()
    {
        do_accept();
    }

private:
    void do_accept()
    {
        acceptor_.async_accept(
            [self = shared_from_this()](beast::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    std::make_shared<http_session>(std::move(socket))->start();
                }
                self->do_accept();
            });
    }

    net::io_context &ioc_;
    tcp::acceptor &acceptor_;
};

// The main function
int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: " << argv[0] << " <port>\n";
            return EXIT_FAILURE;
        }
        auto const address = net::ip::make_address("0.0.0.0");
        auto const port = static_cast<unsigned short>(std::stoi(argv[1]));

        net::io_context ioc{1};

        tcp::acceptor acceptor{ioc, {address, port}};
        std::make_shared<listener>(ioc, acceptor)->start();

        std::vector<std::shared_ptr<net::signal_set>> signals;
        signals.emplace_back(std::make_shared<net::signal_set>(ioc, SIGINT, SIGTERM));
        signals[0]->async_wait([&](beast::error_code const &, int)
                               { ioc.stop(); });

        ioc.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
}

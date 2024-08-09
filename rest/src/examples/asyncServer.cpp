#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <boost/config.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;
//? HANDLER
template <class Body, class Allocator>
http::message_generator handle_request(beast::string_view doc_root, http::request<Body, http::basic_fields<Allocator>> &&req)
{
    std::string json_body = "";
    if (req.method() == http::verb::get)
    {
        json_body = "{\"message\":\"Im just fine i guess\"}";
    }
    else
    {
        json_body = "{\"message\":\"Im not fine i guess\"}";
    }
    http::response<http::string_body> res{http::status::accepted, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "application/json");
    res.body() = json_body;
    res.prepare_payload();
    res.keep_alive(req.keep_alive());
    return res;
}

void fail(beast::error_code ec, char const *what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}

class session : public std::enable_shared_from_this<session>
{
    beast::tcp_stream stream_;
    beast::flat_buffer buffer_;
    std::shared_ptr<std::string const> doc_root_;
    http::request<http::string_body> req_;

public:
    //? Create a session object
    session(
        tcp::socket &&socket,
        std::shared_ptr<std::string const> const &doc_root)
        : stream_(std::move(socket)), doc_root_(doc_root)
    {
    }
    //? Start a asynchronous operation
    void
    run()
    {
        // We need to be executing within a strand to perform async operations
        // on the I/O objects in this session. Although not strictly necessary
        // for single-threaded contexts, this example code is written to be
        // thread-safe by default.
        net::dispatch(stream_.get_executor(),
                      beast::bind_front_handler(
                          &session::do_read,
                          shared_from_this()));
    }

    //? Assync read
    void do_read()
    {
        //?Creating a empty object
        req_ = {};
        //?Set timeout
        stream_.expires_after(std::chrono::seconds(30));
        //? Read a request
        http::async_read(stream_, buffer_, req_, beast::bind_front_handler(&session::on_read, shared_from_this()));
    }

    //? ON read what can we do
    void on_read(
        beast::error_code ec,
        std::size_t bytes_transfered)
    {
        //? IGNORE EMPTY BYTES
        boost::ignore_unused(bytes_transfered);
        //? This means that the connection got closed
        if (ec == http::error::end_of_stream)
        {
            return do_close();
        }
        //? Handle normal error
        if (ec)
        {
            return fail(ec, "read");
        }

        //? SEND RESPONSE
        send_response(
            handle_request(*doc_root_, std::move(req_)));
    }
    //? To send a response we make a async write
    void send_response(http::message_generator &&msg)
    {
        bool keep_alive = msg.keep_alive();
        beast::async_write(
            stream_,
            std::move(msg),
            beast::bind_front_handler(
                &session::on_write, shared_from_this(), keep_alive));
    }

    void on_write(
        bool keep_alive,
        beast::error_code ec,
        std::size_t bytes_transfered)
    {
        boost::ignore_unused(bytes_transfered);
        if (ec)
        {
            return fail(ec, "write");
        }
        //? close in case its not alive
        if (!keep_alive)
        {
            return do_close();
        }
        //? READ ANOTHER REQUEST
        do_read();
    }

    void do_close()
    {
        beast::error_code ec;
        stream_.socket().shutdown(tcp::socket::shutdown_send, ec);
    }
};

class listener : public std::enable_shared_from_this<listener>
{
    net::io_context &ioc_;
    tcp::acceptor acceptor_;
    std::shared_ptr<std::string const> doc_root_;

public:
    listener(
        net::io_context &ioc,
        tcp::endpoint endpoint,
        std::shared_ptr<std::string const> const &doc_root) : ioc_(ioc), acceptor_(net::make_strand(ioc)), doc_root_(doc_root)
    {
        beast::error_code ec;
        //? open the listener
        acceptor_.open(endpoint.protocol(), ec);
        if (ec)
        {
            fail(ec, "open");
            return;
        }
        //? allow address reuse (having more than 1 linkage to the same ip and address)
        acceptor_.set_option(net::socket_base::reuse_address(true), ec);
        if (ec)
        {
            fail(ec, "set_option");
            return;
        }
        //? bind the server address
        acceptor_.bind(endpoint, ec);
        if (ec)
        {
            fail(ec, "bind");
            return;
        }
        //? start listening
        acceptor_.listen(net::socket_base::max_listen_connections, ec);
        if (ec)
        {
            fail(ec, "listen");
            return;
        }
    }

    //? FOR START
    void run()
    {
        do_accept();
    }

private:
    void do_accept()
    {
        acceptor_.async_accept(
            net::make_strand(ioc_),
            beast::bind_front_handler(
                &listener::on_accept,
                shared_from_this()));
    }
    void on_accept(beast::error_code ec, tcp::socket socket)
    {
        if (ec)
        {
            fail(ec, "accept");
            return;
        }
        else
        {
            std::make_shared<session>(
                std::move(socket),
                doc_root_)
                ->run();
        }
        do_accept();
    }
};

int main(int argc, char *argv[])
{
    net::ip::address_v4 const address = net::ip::address_v4::loopback();
    int const port = 80;
    std::shared_ptr<std::string> const doc_root = std::make_shared<std::string>(".");
    int const threads = 5;
    //? This takes the number of threads serving requests
    net::io_context ioc{5};
    std::make_shared<listener>(
        ioc,
        tcp::endpoint{address, port},
        doc_root)
        ->run();
    //? Run the threads
    std::vector<std::thread> v;
    //? creates a given fixed size
    v.reserve(threads - 1);
    for (int i = threads - 1; i > 0; --i)
    {
        v.emplace_back(
            [&ioc]
            {
                ioc.run();
            });
    }
    //? run main thread otherwise it will not keep up
    ioc.run();
    return EXIT_SUCCESS;
}

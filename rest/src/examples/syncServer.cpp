#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/config.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

std::string
path_cat(
    beast::string_view base,
    beast::string_view path)
{
    if (base.empty())
        return std::string(path);
    std::string result(base);
#ifdef BOOST_MSVC
    char constexpr path_separator = '\\';
    if (result.back() == path_separator)
        result.resize(result.size() - 1);
    result.append(path.data(), path.size());
    for (auto &c : result)
        if (c == '/')
            c = path_separator;
#else
    char constexpr path_separator = '/';
    if (result.back() == path_separator)
        result.resize(result.size() - 1);
    result.append(path.data(), path.size());
#endif
    return result;
}

//? Return a response for the given request
template <class Body, class Allocator>
http::message_generator handle_request(
    beast::string_view doc_root,
    http::request<Body, http::basic_fields<Allocator>> &&req)
{
    std::cout << "doc_root -> " << doc_root << "\n";
    std::cout << "target ->" << req.target() << "\n";
    //? doc_root is the reason for this bad request

    //? Lambda function for a bad request
    auto const bad_request = [&req](beast::string_view why)
    {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        //? This is for reutilization of the connection
        res.keep_alive(req.keep_alive());
        res.body() = std::string(why);
        res.prepare_payload();
        return res;
    };

    //? Lambda function for not found
    auto const not_found = [&req](beast::string_view target)
    {
        http::response<http::string_body> res{http::status::not_found, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.body() = "The resource " + std::string(target) + "was not found";
        res.prepare_payload();
    };

    // Returns a server error response
    auto const server_error = [&req](beast::string_view what)
    {
        http::response<http::string_body> res{http::status::internal_server_error, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = "An error occurred: '" + std::string(what) + "'";
        res.prepare_payload();
        return res;
    };

    // Make sure we can handle the method
    if (req.method() != http::verb::get &&
        req.method() != http::verb::head)
        return bad_request("Unknown HTTP-method");

    // Request path must be absolute and not contain "..".
    if (req.target().empty() ||
        req.target()[0] != '/' ||
        req.target().find("..") != beast::string_view::npos)
        return bad_request("Illegal request-target");

    // Respond to HEAD request (ONLY REQUESTING THE HEADER and not GET)
    if (req.method() == http::verb::head)
    {
        http::response<http::empty_body> res{http::status::ok, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        return res;
    }

    http::response<http::string_body> res{http::status::ok, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "application/json");
    res.keep_alive(req.keep_alive());
    std::string json_body = "{\"success\": \"Everything is just fine\"}";
    res.body() = json_body;
    res.prepare_payload();
    return res;
}

// Report a failure
void fail(beast::error_code ec, char const *what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}

void do_session(
    tcp::socket &socket,
    std::shared_ptr<std::string const> const &doc_root)
{
    //? Error code case it exists it will get mutated
    beast::error_code ec;

    //? buffer must persist across reads
    beast::flat_buffer buffer;
    for (;;)
    {
        //? req
        http::request<http::string_body> req;
        http::read(socket, buffer, req, ec);
        if (ec == http::error::end_of_stream)
        {
            break;
        }
        if (ec)
        {
            return fail(ec, "read");
        }
        //? handle the request
        http::message_generator msg = handle_request(*doc_root, std::move(req));
        bool keep_alive = msg.keep_alive();
        //? write the request/send
        beast::write(socket, std::move(msg), ec);
        if (ec)
        {
            return fail(ec, "write");
        }
        if (!keep_alive)
        {
            break;
        }
    }
    //? shutdown socket gracefully
    socket.shutdown(tcp::socket::shutdown_send, ec);
}

int main(int argc, char *argv[])
{
    int const port = 7000;
    std::shared_ptr<std::string> const doc_root = std::make_shared<std::string>(".");

    net::io_context ioc{1};

    //? init acceptor to accept incoming connections
    tcp::acceptor acceptor{ioc, {net::ip::address_v4::loopback(), port}};

    for (;;)
    {
        //? THis receives the net connection
        tcp::socket socket{ioc};
        //? Block until get connection
        acceptor.accept(socket);
        //? Launch session and transfer ownership of the socket
        std::thread{std::bind(
                        &do_session,
                        std::move(socket),
                        doc_root)}
            .detach();
    }
    return 0;
}
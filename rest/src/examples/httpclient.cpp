#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
int main(int argc, char **argv)
{
    //! Usage is http-client-sync <host> <port> <target> <HTTP VERSION (ONLY 1 AND 1.0)>
    //? Like http-client-sync www.example.com 80 1.0
    std::string const host = "www.google.com";
    std::string const port = "80";
    std::string const target = "/";
    std::string const version = "1.0";
    int const version_int = version == "1.0" ? 10 : 11;

    //? INIT IO CONTEXT WHICH IS FROM ASIO TO MANAGE CONTEXT AORUND ASYNC OPERATIONS
    net::io_context ioc;

    //? THE OBJECTS THAT PERFORM THE I/O
    //? This resolves the dns name for a ip address
    tcp::resolver resolver(ioc);
    //? This is the stream used to connect to a remote endpoint
    beast::tcp_stream stream(ioc);

    //? Make lookup
    std::cout << "**************************" << "\n";
    auto const results = resolver.resolve(host, port);
    for (const auto &entry : results)
    {
        std::cout << "Address: " << entry.endpoint().address().to_string()
                  << ", Port; " << entry.endpoint().port() << "\n";
    }
    std::cout << "**************************" << "\n";
    //? Make the connection based on the results (resolution)
    stream.connect(results);

    //? CREATE THE REQUEST MESSAGE
    http::request<http::string_body> req{http::verb::get, target, version_int};
    //? SET THE HEADERS
    //? HOST
    req.set(http::field::host, host);
    //? CLIENT TYPE
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    //? SEND THE HTTP REQUEST
    http::write(stream, req);

    //? Buffer to store the received message
    beast::flat_buffer buffer;

    //? Container for the response
    http::response<http::dynamic_body> res;

    //? Read the answer
    http::read(stream, buffer, res);

    //? Response
    std::cout << res << "\n";

    //? Close the resources
    beast::error_code ec;
    stream.socket().shutdown(tcp::socket::shutdown_both, ec);

    if (ec && ec != beast::errc::not_connected)
    {
        std::cerr << "Some error occured while closing the socket out " << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
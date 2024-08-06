// main.cpp
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        // Create an I/O context
        boost::asio::io_context io_context;

        // Create a resolver to turn a query into a list of endpoints
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("example.com", "80");

        // Create and connect the socket
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // Form the request
        std::string request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
        
        // Send the request
        boost::asio::write(socket, boost::asio::buffer(request));

        // Read the response
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        // Print the response
        std::istream response_stream(&response);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);

        if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
            std::cout << "Invalid response\n";
            return 1;
        }

        if (status_code != 200) {
            std::cout << "Response returned with status code " << status_code << "\n";
            return 1;
        }

        std::cout << "Response returned with status code " << status_code << "\n";

        // Read the response headers, which are terminated by a blank line
        boost::asio::read_until(socket, response, "\r\n\r\n");

        // Print the response headers
        std::string header;
        while (std::getline(response_stream, header) && header != "\r") {
            std::cout << header << "\n";
        }
        std::cout << "\n";

        // Write whatever content we already have to output
        if (response.size() > 0)
            std::cout << &response;

        // Read until EOF, writing data to output as we go
        boost::system::error_code error;
        while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error)) {
            std::cout << &response;
        }

        if (error != boost::asio::error::eof)
            throw boost::system::system_error(error);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

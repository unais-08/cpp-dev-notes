#include <iostream>      // For input/output operations (cout, cerr)
#include <string>        // For string manipulation
#include <vector>        // For dynamic arrays (though not strictly needed for this basic example)
#include <sys/socket.h>  // For socket programming functions (socket, bind, listen, accept, send, recv)
#include <netinet/in.h>  // For internet address structures (sockaddr_in)
#include <unistd.h>      // For close() function (to close sockets)
#include <arpa/inet.h>   // For inet_ntoa() (to convert IP address to string)

// Define the port number the server will listen on
const int PORT = 8080;
// Define the maximum number of pending connections in the listen queue
const int BACKLOG = 10;
// Define the buffer size for receiving data
const int BUFFER_SIZE = 1024;

int main()
{
    // 1. Create a socket
    // AF_INET: IPv4 Internet protocols
    // SOCK_STREAM: Provides sequenced, reliable, two-way, connection-based byte streams (TCP)
    // 0: Default protocol (TCP for SOCK_STREAM)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        std::cerr << "Error: Could not create socket." << std::endl;
        return 1;  // Indicate an error
    }
    std::cout << "Socket created successfully." << std::endl;

    // Optional: Set socket options to reuse address.
    // This helps in cases where the server is restarted quickly, preventing "Address already in
    // use" errors.
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        std::cerr << "Warning: setsockopt failed." << std::endl;
    }

    // 2. Prepare the server address structure
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;          // IPv4
    server_address.sin_addr.s_addr = INADDR_ANY;  // Listen on all available network interfaces
    server_address.sin_port = htons(PORT);        // Convert port number to network byte order

    // 3. Bind the socket to the specified IP address and port
    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        std::cerr << "Error: Could not bind socket to port " << PORT << "." << std::endl;
        close(server_fd);  // Close the socket before exiting
        return 1;
    }
    std::cout << "Socket bound to port " << PORT << "." << std::endl;

    // 4. Listen for incoming connections
    // BACKLOG: Maximum number of pending connections in the queue
    if (listen(server_fd, BACKLOG) == -1)
    {
        std::cerr << "Error: Could not listen on socket." << std::endl;
        close(server_fd);
        return 1;
    }
    std::cout << "Server listening on port " << PORT << "..." << std::endl;

    // Main server loop: Accept and handle client connections indefinitely
    while (true)
    {
        sockaddr_in client_address;
        socklen_t client_addr_len = sizeof(client_address);

        // 5. Accept an incoming connection
        // This call blocks until a client connects
        int client_socket = accept(server_fd, (struct sockaddr*)&client_address, &client_addr_len);
        if (client_socket == -1)
        {
            std::cerr << "Error: Could not accept client connection." << std::endl;
            continue;  // Continue to the next iteration of the loop
        }

        // Log client connection details
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), client_ip, INET_ADDRSTRLEN);
        std::cout << "Accepted connection from " << client_ip << ":"
                  << ntohs(client_address.sin_port) << std::endl;

        // 6. Read data from the client (the HTTP request)
        char buffer[BUFFER_SIZE] = {0};  // Initialize buffer with zeros
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received == -1)
        {
            std::cerr << "Error: Could not receive data from client." << std::endl;
        }
        else if (bytes_received == 0)
        {
            std::cout << "Client disconnected." << std::endl;
        }
        else
        {
            buffer[bytes_received] = '\0';  // Null-terminate the received data
            std::cout << "Received request:\n" << buffer << std::endl;

            std::string request_str(buffer);
            std::string http_response;
            std::string response_body;
            std::string content_type = "text/plain";  // Default content type

            // Simple parsing of the request line to get the path
            size_t get_pos = request_str.find("GET ");
            size_t http_pos = request_str.find(" HTTP/");

            if (get_pos != std::string::npos && http_pos != std::string::npos &&
                http_pos > get_pos + 4)
            {
                std::string path = request_str.substr(get_pos + 4, http_pos - (get_pos + 4));
                std::cout << "Requested Path: " << path << std::endl;

                if (path == "/admin")
                {
                    response_body = "Hello from Admin Page!";
                }
                else if (path == "/users")
                {
                    // Send JSON response for /users
                    response_body =
                        "[\n"
                        "  {\"id\": 1, \"name\": \"Alice\"},\n"
                        "  {\"id\": 2, \"name\": \"Bob\"}\n"
                        "]";
                    content_type = "application/json";  // Set content type for JSON
                }
                else if (path == "/api/all-users")
                {
                    response_body =
                        "[\n"
                        "  {\"id\": 1, \"name\": \"Alice\"},\n"
                        "  {\"id\": 2, \"name\": \"Bob\"},\n"
                        "  {\"id\": 3, \"name\": \"john\"},\n"
                        "  {\"id\": 4, \"name\": \"rehan\"},\n"
                        "  {\"id\": 5, \"name\": \"shaikh\"},\n"
                        "  {\"id\": 6, \"name\": \"vishal\"},\n"
                        "  {\"id\": 7, \"name\": \"aashutosh\"},\n"
                        "  {\"id\": 8, \"name\": \"Unais\"},\n"
                        "  {\"id\": 9, \"name\": \"brendon\"},\n"
                        "]";
                    content_type = "application/json";  // Set content type for JSON
                }
                else
                {
                    response_body = "Hello, World!";
                }
            }
            else
            {
                // Default response if parsing fails
                response_body = "Hello, World!";
            }

            // 7. Prepare the HTTP response with dynamic content length and type
            http_response =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: " +
                content_type +
                "\r\n"  // Use the determined content type
                "Content-Length: " +
                std::to_string(response_body.length()) +
                "\r\n"
                "\r\n" +
                response_body;

            // 8. Send the HTTP response to the client
            ssize_t bytes_sent =
                send(client_socket, http_response.c_str(), http_response.length(), 0);
            if (bytes_sent == -1)
            {
                std::cerr << "Error: Could not send response to client." << std::endl;
            }
            else
            {
                std::cout << "Response sent to client." << std::endl;
            }
        }

        // 9. Close the client socket
        close(client_socket);
        std::cout << "Client socket closed." << std::endl;
    }

    // This part of the code will not be reached in this infinite loop,
    // but it's good practice to close the server socket if the loop were to exit.
    close(server_fd);
    return 0;
}

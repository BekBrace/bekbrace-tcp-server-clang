// The #include directive in C is used to include header files, which are similar 
// in concept to the import statement in Python and javascript for instance.

#include <stdio.h>                  // Include the standard input-output library
#include <stdlib.h>                 // Include the standard library
#include <string.h>                 // Include the string manipulation library
#include <unistd.h>                 // Include the POSIX operating system API library
#include <arpa/inet.h>              // Include the Internet address manipulation library

// The #define directive in C is used for creating constants or macros.
#define PORT 8080                    // Define the port number as 8080
#define BUFFER_SIZE 1024             // Define the buffer size as 1024

// #define SQUARE(x) (x*x) -- A Macro in C
// SQUARE = lambda x : x*x -- Lambda function in Python

// #define PI 3.14 - A symbolic constant in C
// const PI = 3.14 - A constant in JavaScript

// This is the program's entry point
int main() {                         // Main function begins
    int server_fd, new_socket;       // Declare integer variables for socket file descriptors
    struct sockaddr_in address;      // Declare a structure to hold socket address information
    int opt = 1;                     // Declare an integer variable for socket options
    int addrlen = sizeof(address);   // Declare an integer variable for the size of the address structure
    char buffer[BUFFER_SIZE] = {0};  // Declare a character array buffer and initialize it with zeros

    // Create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {  // If socket creation fails, print an error message and exit
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {  // If setting socket options fails, print an error message and exit
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    address.sin_family = AF_INET;                    // Set the address family to AF_INET (IPv4)
    address.sin_addr.s_addr = INADDR_ANY;            // Set the IP address to INADDR_ANY (accept connections on any available interface)
    address.sin_port = htons(PORT);                  // Set the port number in network byte order

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {  // If binding the socket fails, print an error message and exit
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {  // If starting to listen for connections fails, print an error message and exit
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);  // Print a message indicating that the server is listening on the specified port

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {  // If accepting a connection fails, print an error message and exit
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted\n");  // Print a message indicating that a connection has been accepted

    // Read data from the client and print it
    ssize_t valread;  // Declare a signed size type variable for the number of bytes read
    while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) {  // While there is data to be read, print it and clear the buffer
        printf("Client: %s", buffer);
        memset(buffer, 0, sizeof(buffer));  // Clear the buffer
    }

    // Close the socket
    close(server_fd);  // Close the server socket

    return 0;  // Return 0 to indicate successful execution
}

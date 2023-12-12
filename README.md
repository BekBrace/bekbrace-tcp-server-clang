# Simple C Socket Server

This is a basic C program that demonstrates the implementation of a simple socket server. 

The program creates a socket, binds it to a specified port, and listens for incoming connections. 

When a connection is accepted, it reads data from the client and prints it.

## Prerequisites

Make sure you have a C compiler installed on your system, such as GCC.

## Clone the repo
```bash
git clone https://github.com/BekBrace/bekbrace-tcp-server-clang.git
cd simple-c-socket-server
```

## Compile the program
```bash
gcc server.c -o server
```

## Run the program
```bash
./server
```

The server will listen on port 8080, and you can modify the PORT constant in the code if needed.

# Contributing
Contributions are welcome! If you find any issues or have suggestions for improvement, feel free to open an issue or create a pull request.

# License
This project is licensed under the MIT License - see the LICENSE file for details.

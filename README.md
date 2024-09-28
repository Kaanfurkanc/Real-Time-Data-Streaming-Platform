# Real-Time-Data-Streaming-Platform
A C++ real-time data streaming platform that supports multiple data sources, utilizing TCP/IP and UDP multicast for secure and efficient data transmission. Includes multithreading, data compression, and optional TLS/SSL encryption for secure communication.

## Overview
The **Real-Time Data Streaming Platform** is a C++ project designed to handle multiple data streams and deliver them in real-time to multiple clients. The platform uses TCP/IP for reliable data transmission and UDP multicast for efficient broadcast of real-time data. Additionally, it supports multithreading to manage parallel data streams and includes TLS/SSL encryption for secure communication.

This platform can be used for a variety of applications such as:
- Real-time financial data delivery
- Sensor data streaming in IoT systems
- Live multimedia streaming
- High-performance distributed computing

## Features
- **Real-Time Data Streaming**: Provides real-time data to multiple clients through TCP/IP and UDP multicast protocols.
- **Multithreading**: Utilizes multithreading to manage parallel data streams, improving the platform’s performance.
- **Security**: Optional TLS/SSL encryption for secure data transmission using OpenSSL.
- **Asynchronous I/O**: Efficiently handles data streams using non-blocking I/O.
- **Data Compression**: Optionally compresses data streams for better network performance.
- **Cross-Platform**: Designed to work on both Linux and Windows systems.

## Technologies Used
- **C++17**: Modern C++ features for clean and efficient code.
- **POSIX Sockets**: For cross-platform networking.
- **TCP/IP & UDP Multicast**: Network communication protocols for reliable and fast data transfer.
- **Multithreading**: Managed with C++ standard libraries (`std::thread`, `std::mutex`, `std::condition_variable`).
- **TLS/SSL Encryption**: Implemented using OpenSSL for secure communication.
- **Asynchronous I/O**: For non-blocking input/output operations, improving scalability and performance.
- **CMake**: Used as the build system for managing the project structure.

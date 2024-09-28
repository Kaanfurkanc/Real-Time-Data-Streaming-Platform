cmake_minimum_required(VERSION 3.10)

project(RealTimeDataStreaming)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Source Files
add_executable(server src/server.cpp src/utils.cpp)
add_executable(client src/client.cpp src/utils.cpp)

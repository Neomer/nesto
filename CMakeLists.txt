cmake_minimum_required(VERSION 3.14)
project(Nesto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Nesto main.cpp logs/Logger.cpp logs/Logger.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(Nesto wsock32 ws2_32)
endif()
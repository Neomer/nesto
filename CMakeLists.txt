cmake_minimum_required(VERSION 3.14)
project(Nesto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Nesto main.cpp logs/Logger.cpp logs/Logger.h core/JsonSerializable.h core/JsonSerializable.cpp core/StringSerializable.cpp core/StringSerializable.h core/config/Configuration.cpp core/config/Configuration.h core/config/ApplicationConfiguration.cpp core/config/ApplicationConfiguration.h threads/BackgroundService.cpp threads/BackgroundService.h network/TcpSocket.cpp network/TcpSocket.h os.h core/data/DataProvider.cpp core/data/DataProvider.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(Nesto wsock32 ws2_32)
endif()
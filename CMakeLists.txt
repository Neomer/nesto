cmake_minimum_required(VERSION 3.14)
project(Nesto)

set(CMAKE_CXX_STANDARD 17)
set( $NAMESPACES_OPEN = "namespace nesto {" )


add_executable(Nesto main.cpp logs/Logger.cpp logs/Logger.h core/JsonSerializable.h core/JsonSerializable.cpp core/StringSerializable.cpp core/StringSerializable.h core/config/Configuration.cpp core/config/Configuration.h core/config/ApplicationConfiguration.cpp core/config/ApplicationConfiguration.h threads/BackgroundService.cpp threads/BackgroundService.h network/TcpSocket.cpp network/TcpSocket.h os.h core/data/DataProvider.cpp core/data/DataProvider.h logs/LogProvider.cpp logs/LogProvider.h core/data/models/StoredFile.cpp core/data/models/StoredFile.h core/data/SeparatelyStoredFileStream.cpp core/data/SeparatelyStoredFileStream.h core/data/models/IndexFile.cpp core/data/models/IndexFile.h core/security/HashProvider.cpp core/security/HashProvider.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(Nesto wsock32 ws2_32)
endif()

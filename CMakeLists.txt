cmake_minimum_required(VERSION 3.23)

project(meta_server)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
include_directories(/Users/yanaalekseeva/homebrew/Cellar/libpqxx/7.7.4/include)
link_directories(/Users/yanaalekseeva/homebrew/Cellar/libpqxx/7.7.4/lib
        /Users/yanaalekseeva/homebrew/Cellar/libpq/15.1/lib)
find_package(PostgreSQL REQUIRED)
find_package(Poco REQUIRED COMPONENTS Net Foundation)
include_directories(
        Poco::Foundation
        Poco::Net
)

set(CMAKE_CXX_STANDARD 17)

add_executable(meta_server main.cpp DatabaseConnection.cpp DatabaseConnection.h PlayerRepository.cpp PlayerRepository.h DataBase.cpp DataBase.h metaserver/Factory/BaseHTTPHandler.cpp metaserver/Factory/BaseHTTPHandler.h metaserver/Factory/HandlerFactory.cpp metaserver/Factory/HandlerFactory.h)

target_link_libraries(meta_server PUBLIC
        Poco::Foundation
        Poco::Net
        )
#find_library(PQXX_LIB pqxx)
#find_library(PQ_LIB pq)

#set(CMAKE_CXX_FLAGS -lpqxx -lpq -I/usr/local/include -L/usr/local/lib)


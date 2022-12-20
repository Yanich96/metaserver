cmake_minimum_required(VERSION 3.23)

project(meta_server)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
include_directories(/Users/yanaalekseeva/homebrew/Cellar/libpqxx/7.7.4/include)
link_directories(/Users/yanaalekseeva/homebrew/Cellar/libpqxx/7.7.4/lib
        /Users/yanaalekseeva/homebrew/Cellar/libpq/15.1/lib)
find_package(PostgreSQL REQUIRED)
find_package(Poco REQUIRED COMPONENTS Net Foundation JSON)
include_directories(
        Poco::Foundation
        Poco::Net
        Poco::JSON
)

set(CMAKE_CXX_STANDARD 17)

add_executable(meta_server main.cpp metaserver/Database/DatabaseConnection.cpp metaserver/Database/DatabaseConnection.h metaserver/Database/PlayerRepository.cpp metaserver/Database/PlayerRepository.h metaserver/Database/DataBase.cpp metaserver/Database/DataBase.h metaserver/Factory/BaseHTTPHandler.cpp metaserver/Factory/BaseHTTPHandler.h metaserver/Factory/HandlerFactory.cpp metaserver/Factory/HandlerFactory.h metaserver/Factory/Handlers/RegisterNewGamerHTTPHandler.cpp metaserver/Factory/Handlers/RegisterNewGamerHTTPHandler.h metaserver/Factory/Handlers/LoginGamerHTTPHandler.cpp metaserver/Factory/Handlers/LoginGamerHTTPHandler.h metaserver/Factory/Handlers/SaveGameHTTPHandler.cpp metaserver/Factory/Handlers/SaveGameHTTPHandler.h metaserver/Factory/Handlers/StatisticGamerHTTPHandler.cpp metaserver/Factory/Handlers/StatisticGamerHTTPHandler.h BlockingQueue.h metaserver/Database/GameRepository.cpp metaserver/Database/GameRepository.h metaserver/Factory/Handlers/ChangeNameHTTPHandler.cpp metaserver/Factory/Handlers/ChangeNameHTTPHandler.h)

target_link_libraries(meta_server PUBLIC
        Poco::Foundation
        Poco::Net
        Poco::JSON
        )


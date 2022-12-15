//
// Created by Yana Alekseeva on 29.11.2022.
//

#include "DataBase.h"

#include <memory>


DataBase::DataBase(int connectionPoolSize) {
    for (int i = 0; i < connectionPoolSize; ++i) {
        connectionPool.push(std::shared_ptr<DatabaseConnection>());
    }
}

std::unique_ptr<work, Deleter> DataBase::openTransaction() {
    auto connection = connectionPool.pop();
    return connection->openTransaction([&]() {
        this->connectionPool.push(connection);
    });
}

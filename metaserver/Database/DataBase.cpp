#include "DataBase.h"

#include <memory>


DataBase::DataBase(int connectionPoolSize) {
    for (int i = 0; i < connectionPoolSize; ++i) {
        connectionPool.push(std::make_shared<DatabaseConnection>());
    }
}

std::shared_ptr<work> DataBase::openTransaction() {
    auto connection = connectionPool.pop();
    return connection->openTransaction([this, connection]() {
        this->connectionPool.push(connection);
    });
}

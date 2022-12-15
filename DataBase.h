//
// Created by Yana Alekseeva on 29.11.2022.
//

#ifndef META_SERVER_DATABASE_H
#define META_SERVER_DATABASE_H
#include <queue>

#include "DatabaseConnection.h"
#include "BlockingQueue.h"


class DataBase {
    BlockingQueue<std::shared_ptr<DatabaseConnection>> connectionPool;
    DataBase(int connectionPoolSize);
    std::unique_ptr<work, Deleter> openTransaction();
};


#endif //META_SERVER_DATABASE_H

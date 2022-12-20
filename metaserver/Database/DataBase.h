#ifndef META_SERVER_DATABASE_H
#define META_SERVER_DATABASE_H

#include <queue>

#include "DatabaseConnection.h"
#include "../../BlockingQueue.h"


class DataBase {
    BlockingQueue<std::shared_ptr<DatabaseConnection>> connectionPool;

public:
    DataBase(int connectionPoolSize);

    std::shared_ptr<work> openTransaction();
};


#endif //META_SERVER_DATABASE_H

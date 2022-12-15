//
// Created by Yana Alekseeva on 25.11.2022.
//

#ifndef META_SERVER_DATABASECONNECTION_H
#define META_SERVER_DATABASECONNECTION_H

#include <memory>
#include <pqxx/pqxx>


using namespace pqxx;

class Deleter {
    std::function<void(void)> afterDelete;
public:

    explicit Deleter(const std::function<void(void)> afterDelete) : afterDelete(afterDelete) {
    }

    constexpr void operator()(work *arg) const {
        arg->commit();
        delete arg;
        afterDelete();
    }
};

class DatabaseConnection {
    connection _connection;

    void prepare_my_statement(pqxx::connection_base &c);

public:
    DatabaseConnection() : _connection(
            "dbname = postgres user = postgres password = 51255 hostaddr = 127.0.0.1 port = 5432") {
        prepare_my_statement(_connection);
    };

    ~DatabaseConnection() {
        _connection.close();
    };

    std::unique_ptr<work, Deleter> openTransaction(const std::function<void()> &onClose) {
        return std::unique_ptr<work, Deleter>{new work(_connection), Deleter(onClose)};
    };
};


#endif //META_SERVER_DATABASECONNECTION_H

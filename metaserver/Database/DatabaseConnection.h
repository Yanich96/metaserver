#ifndef META_SERVER_DATABASECONNECTION_H
#define META_SERVER_DATABASECONNECTION_H

#include <memory>
#include <pqxx/pqxx>


using namespace pqxx;

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

    std::shared_ptr<work> openTransaction(std::function<void()> onClose) {
        return std::shared_ptr<work>{
                new work(_connection),
                [&, onClose](work *arg) {
                    arg->commit();
                    delete arg;
                    onClose();
                }};
    };
};


#endif //META_SERVER_DATABASECONNECTION_H

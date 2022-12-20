#ifndef META_SERVER_STATISTICGAMERHTTPHANDLER_H
#define META_SERVER_STATISTICGAMERHTTPHANDLER_H

#include "../BaseHTTPHandler.h"

class StatisticGamerHTTPHandler : public BaseHTTPHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;

    StatisticGamerHTTPHandler(DataBase &dataBase);

private:
    DataBase &dataBase;
};


#endif //META_SERVER_STATISTICGAMERHTTPHANDLER_H

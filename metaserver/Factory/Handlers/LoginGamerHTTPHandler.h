#ifndef META_SERVER_LOGINGAMERHTTPHANDLER_H
#define META_SERVER_LOGINGAMERHTTPHANDLER_H

#include "../BaseHTTPHandler.h"
#include <Poco/Net/HTTPServerResponse.h>

class LoginGamerHTTPHandler : public BaseHTTPHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;

    explicit LoginGamerHTTPHandler(DataBase &dataBase);

private:
    DataBase &dataBase;
};


#endif //META_SERVER_LOGINGAMERHTTPHANDLER_H

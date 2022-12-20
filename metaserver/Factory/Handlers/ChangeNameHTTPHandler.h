#ifndef META_SERVER_CHANGENAMEHTTPHANDLER_H
#define META_SERVER_CHANGENAMEHTTPHANDLER_H

#include "../BaseHTTPHandler.h"
#include <Poco/Net/HTTPServerResponse.h>


class ChangeNameHTTPHandler : public BaseHTTPHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;

    explicit ChangeNameHTTPHandler(DataBase &dataBase);

private:
    DataBase &dataBase;
};


#endif //META_SERVER_CHANGENAMEHTTPHANDLER_H

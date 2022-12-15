//
// Created by Yana Alekseeva on 14.12.2022.
//

#ifndef META_SERVER_REGISTERNEWGAMERHTTPHANDLER_H
#define META_SERVER_REGISTERNEWGAMERHTTPHANDLER_H
#include "../BaseHTTPHandler.h"
#include <iostream>


class RegisterNewGamerHTTPHandler : public BaseHTTPHandler{
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;

};


#endif //META_SERVER_REGISTERNEWGAMERHTTPHANDLER_H

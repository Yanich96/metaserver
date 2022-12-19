//
// Created by Yana Alekseeva on 13.12.2022.
//

#ifndef META_SERVER_HANDLERFACTORY_H
#define META_SERVER_HANDLERFACTORY_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include "../Database/DataBase.h"
class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory{
public:
    HandlerFactory(): dataBase(5) { }

    Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request) override;
private:
    DataBase dataBase;
};


#endif //META_SERVER_HANDLERFACTORY_H

//
// Created by Yana Alekseeva on 13.12.2022.
//

#ifndef META_SERVER_HANDLERFACTORY_H
#define META_SERVER_HANDLERFACTORY_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>
class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory{
public:
    Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request) override;

};


#endif //META_SERVER_HANDLERFACTORY_H

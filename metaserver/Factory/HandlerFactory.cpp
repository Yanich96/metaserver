//
// Created by Yana Alekseeva on 13.12.2022.
//

#include "HandlerFactory.h"
#include <Poco/Net/HTTPServerRequest.h>

Poco::Net::HTTPRequestHandler *HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request) {
    auto uri = request.getURI();
    if (uri == "/player/registration")
        return nullptr;
    return nullptr;
}

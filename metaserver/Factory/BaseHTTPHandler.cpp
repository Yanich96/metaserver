//
// Created by Yana Alekseeva on 13.12.2022.
//

#include "BaseHTTPHandler.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <iostream>

Poco::JSON::Object::Ptr BaseHTTPHandler::body(Poco::Net::HTTPServerRequest &request) {
    auto &u = request.stream();
    Poco::JSON::Parser parser;
    auto result = parser.parse(u);
    Poco::JSON::Object::Ptr pObject = result.extract<Poco::JSON::Object::Ptr>();
    return pObject;
}

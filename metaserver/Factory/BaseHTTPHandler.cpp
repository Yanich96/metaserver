#include "BaseHTTPHandler.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>

Poco::JSON::Object::Ptr BaseHTTPHandler::body(Poco::Net::HTTPServerRequest &request) {
    Poco::JSON::Parser parser;
    auto result = parser.parse(request.stream());
    return result.extract<Poco::JSON::Object::Ptr>();
}

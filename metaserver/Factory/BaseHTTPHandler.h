//
// Created by Yana Alekseeva on 13.12.2022.
//

#ifndef META_SERVER_BASEHTTPHANDLER_H
#define META_SERVER_BASEHTTPHANDLER_H

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/JSON/Parser.h>

class BaseHTTPHandler : public Poco::Net::HTTPRequestHandler{
public:
    Poco::JSON::Object::Ptr body(Poco::Net::HTTPServerRequest &request);
};


#endif //META_SERVER_BASEHTTPHANDLER_H

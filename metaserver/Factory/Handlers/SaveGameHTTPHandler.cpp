//
// Created by Yana Alekseeva on 14.12.2022.
//

#include "SaveGameHTTPHandler.h"

void
SaveGameHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    std::string winGamer = parsedJson->get("winGamer");
    std::string winlessGamer = parsedJson->get("winlessGamer");

}

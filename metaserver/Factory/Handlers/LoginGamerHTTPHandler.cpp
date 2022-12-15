//
// Created by Yana Alekseeva on 14.12.2022.
//

#include "LoginGamerHTTPHandler.h"

void
LoginGamerHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    std::string loginUser = parsedJson->get("Login");
    std::string numberPhoneUser = parsedJson->get("NumberPhone");

}

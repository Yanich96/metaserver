//
// Created by Yana Alekseeva on 14.12.2022.
//

#include "RegisterNewGamerHTTPHandler.h"


void RegisterNewGamerHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request,
                                                Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    std::string nameUser = parsedJson->get("Name");
    std::string numberPhoneUser = parsedJson->get("NumberPhone");
}

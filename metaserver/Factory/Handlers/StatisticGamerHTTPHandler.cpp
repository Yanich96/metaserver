//
// Created by Yana Alekseeva on 14.12.2022.
//

#include "StatisticGamerHTTPHandler.h"

void StatisticGamerHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request,
                                              Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    std::string nameUser = parsedJson->get("Name");
    int countWin = parsedJson->get("countWin");

}

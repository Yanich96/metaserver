//
// Created by Yana Alekseeva on 13.12.2022.
//

#include "HandlerFactory.h"
#include <Poco/Net/HTTPServerRequest.h>
#include "Handlers/LoginGamerHTTPHandler.h"
#include "Handlers/RegisterNewGamerHTTPHandler.h"
#include "Handlers/SaveGameHTTPHandler.h"
#include "Handlers/StatisticGamerHTTPHandler.h"

Poco::Net::HTTPRequestHandler *HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request) {
    auto uri = request.getURI();
    if (uri == "/player/registration")
        return new RegisterNewGamerHTTPHandler(dataBase);

    if (uri == "/player/login")
        return new LoginGamerHTTPHandler(dataBase);

    if (uri == "/game/save")
        return new SaveGameHTTPHandler(dataBase);

    if(uri == "/game/statistic")
        return new StatisticGamerHTTPHandler;

    return nullptr;
}

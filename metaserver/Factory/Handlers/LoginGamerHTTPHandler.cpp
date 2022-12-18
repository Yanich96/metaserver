//
// Created by Yana Alekseeva on 14.12.2022.
//

#include "LoginGamerHTTPHandler.h"

void LoginGamerHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    std::string loginUser = parsedJson->get("Name");
    std::string passwordUser = parsedJson->get("Password");
    PlayerRepository logPlayer;
    std::shared_ptr<work> tx = dataBase.openTransaction();
    int id = logPlayer.loginPlayer(loginUser, passwordUser, tx);
    std::string json = "{\"id\":"+std::to_string(id)+"}";
    response.sendBuffer(json.c_str(), json.size());
}

LoginGamerHTTPHandler::LoginGamerHTTPHandler(DataBase &dataBase): dataBase(dataBase){
}

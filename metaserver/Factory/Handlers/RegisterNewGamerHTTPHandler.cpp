#include "RegisterNewGamerHTTPHandler.h"
#include <Poco/Net/HTTPServerResponse.h>


void RegisterNewGamerHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request,
                                                Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    Player player;
    player.name = (parsedJson->get("Name")).toString();
    player.password = (parsedJson->get("Password")).toString();
    PlayerRepository newPlayer;
    std::shared_ptr<work> tx = dataBase.openTransaction();
    newPlayer.insertPlayer(player, tx);
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    response.send();
}

RegisterNewGamerHTTPHandler::RegisterNewGamerHTTPHandler(DataBase &dataBase) : dataBase(dataBase) {
}

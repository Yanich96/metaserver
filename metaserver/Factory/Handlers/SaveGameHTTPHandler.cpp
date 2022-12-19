
#include <Poco/Net/HTTPServerResponse.h>
#include "SaveGameHTTPHandler.h"

void
SaveGameHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    int idWinGamer = parsedJson->get("idWinGamer");
    int idWinlessGamer = parsedJson->get("idWinlessGamer");
    std::shared_ptr<work> tx = dataBase.openTransaction();
    GameRepository newGame;
    newGame.insertResultGame(idWinGamer, idWinlessGamer, tx);
    PlayerRepository dataGame;
    dataGame.plusOneGame(idWinGamer, idWinlessGamer, tx);
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    response.send();
}

SaveGameHTTPHandler::SaveGameHTTPHandler(DataBase &dataBase): dataBase(dataBase) {

}

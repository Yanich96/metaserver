#include "ChangeNameHTTPHandler.h"
#include <Poco/Net/HTTPServerResponse.h>

void
ChangeNameHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    int id = parsedJson->get("ID");
    std::string newNamedUser = parsedJson->get("NewName");
    std::shared_ptr<work> tx = dataBase.openTransaction();
    PlayerRepository player;
    player.changeName(id, newNamedUser, tx);
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    response.send();
}

ChangeNameHTTPHandler::ChangeNameHTTPHandler(DataBase &dataBase) : dataBase(dataBase) {

}

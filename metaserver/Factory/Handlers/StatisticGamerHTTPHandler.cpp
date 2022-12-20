#include "StatisticGamerHTTPHandler.h"
#include <Poco/Net/HTTPServerResponse.h>


void StatisticGamerHTTPHandler::handleRequest(Poco::Net::HTTPServerRequest &request,
                                              Poco::Net::HTTPServerResponse &response) {
    Poco::JSON::Object::Ptr parsedJson = body(request);
    std::shared_ptr<work> tx = dataBase.openTransaction();
    int idPlayer = parsedJson->get("id");
    PlayerRepository pr;
    int countGames = pr.countGamesPlayer(idPlayer, tx);
    int countWin = pr.countWinPlayer(idPlayer, tx);
    int countWinless = pr.countWinlessPlayer(idPlayer, tx);
    std::string json = "{\"countGames\":" + std::to_string(countGames) + ",\n"
                       + "\"countWin\":" + std::to_string(countWin) + ",\n"
                       + "\"countWinless\":" + std::to_string(countWinless) + "}";
    response.sendBuffer(json.c_str(), json.size());
}

StatisticGamerHTTPHandler::StatisticGamerHTTPHandler(DataBase &dataBase) : dataBase(dataBase) {

}

//
// Created by Yana Alekseeva on 14.12.2022.
//

#ifndef META_SERVER_SAVEGAMEHTTPHANDLER_H
#define META_SERVER_SAVEGAMEHTTPHANDLER_H
#include "../BaseHTTPHandler.h"
#include "../../Database/GameRepository.h"


class SaveGameHTTPHandler: public BaseHTTPHandler{
public:
    SaveGameHTTPHandler(DataBase &dataBase);
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;
    DataBase &dataBase;
};


#endif //META_SERVER_SAVEGAMEHTTPHANDLER_H

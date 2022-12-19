//
// Created by Yana Alekseeva on 18.12.2022.
//

#ifndef META_SERVER_GAMEREPOSITORY_H
#define META_SERVER_GAMEREPOSITORY_H
#include <string>
#include "DatabaseConnection.h"

class GameRepository {
public:
    void insertResultGame(int idWinner, int idWinnerless, std::shared_ptr<work> transaction);

};


#endif //META_SERVER_GAMEREPOSITORY_H

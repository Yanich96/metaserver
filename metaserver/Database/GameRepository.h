#ifndef META_SERVER_GAMEREPOSITORY_H
#define META_SERVER_GAMEREPOSITORY_H

#include <string>
#include "DatabaseConnection.h"

class GameRepository {
public:
    void insertResultGame(int idWinner, int idWinnerless, const std::shared_ptr<work>& transaction);

};


#endif //META_SERVER_GAMEREPOSITORY_H

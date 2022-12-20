#ifndef META_SERVER_PLAYERREPOSITORY_H
#define META_SERVER_PLAYERREPOSITORY_H

#include <string>
#include "DatabaseConnection.h"

struct Player {
    int id;
    std::string name;
    std::string password;
    int countWins = 0;
    int countGames = 0;
};

class PlayerRepository {
public:
    void insertPlayer(const Player &player, const std::shared_ptr<work>& transaction);

    std::optional<Player> player(int id, const std::shared_ptr<work>& transaction);

    int loginPlayer(std::string name, const std::string& password, const std::shared_ptr<work>& transaction);

    void plusOneGame(int idFirstPlayer, int idSecondPlayer, const std::shared_ptr<work>& transaction);

    int countGamesPlayer(int id, const std::shared_ptr<work>& transaction);

    int countWinPlayer(int id, const std::shared_ptr<work>& transaction);

    int countWinlessPlayer(int id, const std::shared_ptr<work>& transaction);

    void changeName(int id, const std::string& newName, const std::shared_ptr<work>& transaction);
};


#endif //META_SERVER_PLAYERREPOSITORY_H

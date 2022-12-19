//
// Created by Yana Alekseeva on 25.11.2022.
//
#ifndef META_SERVER_PLAYERREPOSITORY_H
#define META_SERVER_PLAYERREPOSITORY_H
#include <string>
#include "DatabaseConnection.h"
struct Player
{
    int id;
    std::string  name;
    std::string password;
    int count_wins = 0;
    int count_games = 0;
};
class PlayerRepository {
public:
    void insertPlayer(const Player &player, std::shared_ptr<work> transaction);
    std::optional<Player> player(int id, std::shared_ptr<work> transaction);
    int loginPlayer(std::string name, std::string password, std::shared_ptr<work> transaction);
    void plusOneGame(int idFirstPlayer, int idSecondPlayer, std::shared_ptr<work> transaction);
};


#endif //META_SERVER_PLAYERREPOSITORY_H

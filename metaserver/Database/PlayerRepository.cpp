//
// Created by Yana Alekseeva on 25.11.2022.
//

#include "PlayerRepository.h"

void PlayerRepository::insertPlayer(const Player &player, std::shared_ptr<work> transaction) {
    result R = transaction->exec_prepared("insert_player", player.name, player.password);
}


std::optional<Player> PlayerRepository::player(int id, std::shared_ptr<work> transaction) {
    result R = transaction->exec_prepared("find_player", id);
    if (R.empty())
        return {};
    auto c = R.begin();
    return Player{id, c[0].as<std::string>(), c[2].as<std::string>(),  c[1].as<int>(),c[3].as<int>()};
}

int PlayerRepository::loginPlayer(std::string name, std::string password, std::shared_ptr<work> transaction) {
    result R = transaction->exec_prepared("login_player", name, password);
    if (R.empty())
        return {};
    auto c = *(R.begin());
    return c[0].as<int>();
}

void PlayerRepository::plusOneGame(int idWinPlayer, int idWinlessPlayer, std::shared_ptr<work> transaction) {
    result countGame = transaction->exec_prepared("count_game_players", idWinPlayer, idWinlessPlayer);
    result countWin = transaction->exec_prepared("update_winCount_player", idWinPlayer);
}

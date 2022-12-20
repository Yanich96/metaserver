//
// Created by Yana Alekseeva on 25.11.2022.
//

#include "PlayerRepository.h"

void PlayerRepository::insertPlayer(const Player &player, const std::shared_ptr<work>& transaction) {
    result R = transaction->exec_prepared("insert_player", player.name, player.password);
}


std::optional<Player> PlayerRepository::player(int id, const std::shared_ptr<work>& transaction) {
    result R = transaction->exec_prepared("find_player", id);
    if (R.empty())
        return {};
    auto c = R.begin();
    return Player{id, c[0].as<std::string>(), c[2].as<std::string>(),  c[1].as<int>(),c[3].as<int>()};
}

int PlayerRepository::loginPlayer(std::string name, const std::string& password, const std::shared_ptr<work>& transaction) {
    result R = transaction->exec_prepared("login_player", name, password);
    if (R.empty())
        return {};
    auto c = *(R.begin());
    return c[0].as<int>();
}

void PlayerRepository::plusOneGame(int idWinPlayer, int idWinlessPlayer, const std::shared_ptr<work>& transaction) {
    result countGame = transaction->exec_prepared("update_count_game_players", idWinPlayer, idWinlessPlayer);
    result countWin = transaction->exec_prepared("update_winCount_player", idWinPlayer);
}

int PlayerRepository::countGamesPlayer(int id, const std::shared_ptr<work>& transaction) {
    result R = transaction->exec_prepared("count_game_player", id);
    if (R.empty())
        return {};
    auto c = *(R.begin());
    return c[0].as<int>();
}

int PlayerRepository::countWinPlayer(int id, const std::shared_ptr<work>& transaction) {
    result R = transaction->exec_prepared("count_win_player", id);
    if (R.empty())
        return {};
    auto c = *(R.begin());
    return c[0].as<int>();
}

int PlayerRepository::countWinlessPlayer(int id, const std::shared_ptr<work>& transaction) {
    result R = transaction->exec_prepared("count_winless_player", id);
    if (R.empty())
        return {};
    auto c = *(R.begin());
    return c[0].as<int>();
}

void PlayerRepository::changeName(int id, const std::string& newName, const std::shared_ptr<work>& transaction) {
    result R =transaction->exec_prepared("change_name", newName, id);
}

#include "GameRepository.h"

void GameRepository::insertResultGame(int idWinner, int idWinnerless, const std::shared_ptr<work>& transaction) {
    result R = transaction->exec_prepared("result_game", idWinner, idWinnerless);
}

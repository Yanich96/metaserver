//
// Created by Yana Alekseeva on 18.12.2022.
//

#include "GameRepository.h"

void GameRepository::insertResultGame(int idWinner, int idWinnerless, std::shared_ptr<work> transaction) {
    result R = transaction->exec_prepared("result_game", idWinner, idWinnerless);
}

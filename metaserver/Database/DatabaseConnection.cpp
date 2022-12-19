//
// Created by Yana Alekseeva on 25.11.2022.
//

#include "DatabaseConnection.h"



void DatabaseConnection::prepare_my_statement(connection_base &c) {
    c.prepare(
            "find_player",
            "SELECT NAME, NUMBER_OF_WINS, PASSWORD, COUNT_OF_GAMES FROM WIN_USER WHERE ID=$1");

    c.prepare(
            "insert_player",
            "INSERT INTO WIN_USER(NAME, PASSWORD) VALUES($1, $2)");

    c.prepare(
            "login_player",
            "SELECT ID FROM WIN_USER WHERE NAME=$1 AND PASSWORD=$2"
            );
    c.prepare(
            "result_game",
            "INSERT INTO GAME_RESULT(ID_WINNER, ID_NONWINNER) VALUES($1, $2)"
            );
    c.prepare(
            "count_game_players",
            "UPDATE WIN_USER SET COUNT_OF_GAMES=COUNT_OF_GAMES+1 WHERE ID IN ($1, $2)"
            );
    c.prepare(
            "update_winCount_player",
            "UPDATE WIN_USER SET NUMBER_OF_WINS=NUMBER_OF_WINS+1 WHERE ID=$1"
            );

}

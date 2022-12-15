//
// Created by Yana Alekseeva on 25.11.2022.
//

#include "DatabaseConnection.h"



void DatabaseConnection::prepare_my_statement(connection_base &c) {
    c.prepare(
            "find_player",
            "SELECT NAME, NUMBER_OF_WINS FROM WIN_USER WHERE ID=$1");

    c.prepare(
            "insert_player",
            "INSERT INTO WIN_USER(ID, NAME, NUMBER_OF_WINS) VALUES($1, $2, 0)");
}

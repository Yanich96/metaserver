#include <iostream>
#include <Poco/Net/HTTPServer.h>
#include "DatabaseConnection.h"
#include "PlayerRepository.h"
#include "metaserver/Factory/HandlerFactory.h"


using namespace std;

void f(int a){}

int main() {
    HandlerFactory* factory = new HandlerFactory;
    int a;
    Poco::Net::HTTPServer server(factory, 80);
    std::cin>>a;
    server.stopAll();
    return 0;




//    std::string exec = "CREATE TABLE GAME_RESULT"
//                  "( ID SERIAL PRIMARY KEY NOT NULL, "
//                  "ID_WINNER INT NOT NULL,"
//                  "ID_NONWINNER INT NOT NULL)";
//    db.execute(exec.c_str());


}

#include <iostream>
#include <Poco/Net/HTTPServer.h>
#include "metaserver/Factory/HandlerFactory.h"

using namespace std;


int main() {
    HandlerFactory *factory = new HandlerFactory;
    auto *configs = new Poco::Net::HTTPServerParams{};
    configs->setMaxThreads(10);
    Poco::Net::HTTPServer server(factory, 8080, configs);
    server.start();
    std::cout << "server started";
    int a;
    std::cin >> a;
    server.stopAll();
    return 0;
}

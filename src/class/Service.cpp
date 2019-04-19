#include <iostream>
using namespace std;
#include "Service.hpp"

/* constructs the object and sets default values */
Service::Service(int servicePort){
    this->port = servicePort;
    this->server = new HttpServer(this->port);
}

/* returns whether service is terminated or not */
bool Service::isTerminated(){
    return !this->server->isActive();
}

/* starts the service and listens for requests on the defined port */
bool Service::start(){
    this->server->start();
    return this->server->isActive();
}

string Service::getName(){
    return "CBCDB";
}
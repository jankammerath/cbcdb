#include <iostream>
using namespace std;
#include "Service.hpp"

/* constructs the object and sets default values */
Service::Service(int servicePort){
    this->port = servicePort;
    this->server = new HttpServer(this->port,(void*)Service::handleRequest);
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

void Service::handleRequest(string method, string url, string data){
    cout << "Callback shyte is working nicely: " << method << " " << url << " --- data: " << data << endl;
}

string Service::getName(){
    return "CBCDB";
}
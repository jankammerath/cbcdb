#include <iostream>
using namespace std;
#include "Service.hpp"

/* constructs the object and sets default values */
Service::Service(int servicePort){
    this->terminated = true;
    this->port = servicePort;
}

/* returns whether service is terminated or not */
bool Service::isTerminated(){
    return this->terminated;
}

/* starts the service and listens for requests on the defined port */
bool Service::start(){
    return true;
}

string Service::getName(){
    return "CBCDB";
}
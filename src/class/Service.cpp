#include <iostream>
using namespace std;
#include "Service.hpp"
#include "Request/Request.hpp"

#define SERVICE_NAME "CBCDB"

/* static access to service instance */
Service* Service::instanceRef;

/* constructs the object and sets default values */
Service::Service(int servicePort, string storagePath){
    Service::setInstance(this);
    this->storage = new Storage(storagePath);
    this->server = new HttpServer(servicePort,(void*)Service::handleRequest);
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

/* handles requests and creates service request objects */
string Service::handleRequest(string method, string url, string data){
    /* create the instance of the request class */
    Request* request = Request::createRequest(method,url,data);

    return "";
}

/* returns the name of the service */
string Service::getName(){
    return SERVICE_NAME;
}

void Service::setInstance(Service* newInstance){
    instanceRef = newInstance;
};

Service* Service::getInstance(){
    return instanceRef;
};
#include <iostream>
#include <microhttpd.h>
using namespace std;
#include "HttpServer.hpp"

HttpServer::HttpServer(int serverPort){
    this->port = serverPort;
}

/* starts the http server */
void HttpServer::start(){

}

/* stops the http server */
void HttpServer::stop(){
    MHD_stop_daemon(this->d);
}
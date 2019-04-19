#include <iostream>
#include <microhttpd.h>
using namespace std;
#include "HttpServer.hpp"

/* content type to use for http responses */
#define CONTENT_TYPE "application/json"

HttpServer::HttpServer(int serverPort){
    this->port = serverPort;
}

/* starts the http server */
void HttpServer::start(){
    this->daemonHandle = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION,
		       this->port, NULL, NULL, &HttpServer::handleRequest, NULL, MHD_OPTION_END);
}

/* handles all http requests to this server */
int HttpServer::handleRequest(void * cls, struct MHD_Connection * connection,
		    const char * url, const char * method, const char * version,
            const char * upload_data, size_t * upload_data_size, void ** ptr){
    int result;
    struct MHD_Response* response;

    string jsonResult = "{\"status\":\"fail\"}";

    /* it is absolutely vital to use MHD_RESPMEM_MUST_COPY as otherwise memory exceptions will occur.
        See further information here: https://www.gnu.org/software/libmicrohttpd/manual/html_node/microhttpd_002dresponse-create.html */
    response = MHD_create_response_from_buffer (jsonResult.size(),(void*)jsonResult.c_str(),MHD_RESPMEM_MUST_COPY);
    MHD_add_response_header (response, "Content-Type", CONTENT_TYPE);
    result = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);

    return result;
}

/* stops the http server */
void HttpServer::stop(){
    if(this->daemonHandle != NULL){
        MHD_stop_daemon(this->daemonHandle);
    }
}

/* returns true when server running, otherwise false */
bool HttpServer::isActive(){
    bool result = false;

    if(this->daemonHandle != NULL){ result = true; }

    return result;
}
#include <iostream>
#include "Storage.hpp"
#include "FileSystem.hpp"
using namespace std;

Storage::Storage(string storagePath){
    this->path = storagePath;
}

GetResponse* Storage::execute(GetRequest* request){
    GetResponse* result = new GetResponse();

    return result;
}

Response* Storage::execute(Request* request){
    Response* result = new Response();

    switch(request->getType()){
        case GET:
            /* this is a get request, execute as get request */
            result = this->execute((GetRequest*)request);
            break;
    }

    return result;
}

bool Storage::chainExists(string chainName){
    return FileSystem::fileExists(this->path + "/" + chainName);
}
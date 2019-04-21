#include <iostream>
#include "Storage.hpp"
#include "FileSystem.hpp"
#include "Chain.hpp"
using namespace std;

/* constructs the object and sets the storage path
    where all the database files are to be stored in */
Storage::Storage(string storagePath){
    this->path = storagePath;
}

/* executes a get request and returns a get response
    for database queries on the storage level */
GetResponse* Storage::execute(GetRequest* request){
    GetResponse* result = new GetResponse();

    /* check if the requested chain actually exists */
    if(this->chainExists(request->getChainName())){

    }

    return result;
}

PutResponse* Storage::execute(PutRequest* request){
    PutResponse* result = new PutResponse();

    /* check if the requested chain actually exists */
    if(this->chainExists(request->getChainName())){
        /* execute the block put */
    }else{
        /* when the chain does not exist, create it */
        Chain* chain = Chain::create(this,request->getChainName());
    }

    return result;
}

Response* Storage::execute(Request* request){
    Response* result = new Response();

    switch(request->getType()){
        case GET:
            /* this is a get request, execute as get request */
            result = this->execute((GetRequest*)request);
            break;
        case PUT:
            /* this is a get request, execute as get request */
            result = this->execute((PutRequest*)request);
            break;
    }

    return result;
}

bool Storage::chainExists(string chainName){
    return FileSystem::fileExists(this->path + "/chain/" + chainName);
}
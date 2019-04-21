#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
#include "Request.hpp"
#include "GetRequest.hpp"
#include "PutRequest.hpp"

/* creates a concrete request */
Request* Request::createRequest(string method, string url, string data){
    Request* result = new Request();

    /* create a concrete object for the concrete request */
    if(method == "GET"){
        result = new GetRequest();
    }if(method == "PUT"){
        result = new PutRequest();
    }

    /* get a vector with all path items */
    vector<string> pathList = Request::getPathListFromUrl(url);
    if(pathList.size() > 0){
        /* path contains a chain name */
        result->setChainName(pathList[0]);
    }if(pathList.size() > 1){
        /* path contains a block id */
        result->setBlockId(pathList[1]);
    }

    /* set the data for this request */
    result->setJsonText(data);

    return result;
}

/* returns a vector with all path elements */
vector<string> Request::getPathListFromUrl(string url){
    vector<string> result;

    istringstream f(url);
    string s;    
    while (getline(f, s, '/')) {
        if(!s.empty()){
            result.push_back(s);
        }
    }

    return result;
}
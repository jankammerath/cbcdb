#include <iostream>
#include <vector>
using namespace std;

#pragma once
enum RequestType { GET, PUT, DELETE };

class Request {
    public:
        /* public methods */
        Request(){
            
        };

        void setChainName(string name){
            this->chainName = name;
        }

        void setBlockId(string id){
            this->blockId = id;
        }

        static Request* createRequest(string method, string url, string data);
        
    private:
        /* private methods */
        static vector<string> getPathListFromUrl(string url);

        /* private members */
        RequestType type;
        string chainName;
        string blockId;
};
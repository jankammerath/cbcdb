#include <iostream>
#include <vector>
using namespace std;

#pragma once
enum RequestType { GET, PUT, DELETE };

class Request {
    public:
        /* public methods */
        Request(){
            this->type = GET;
        };

        void setChainName(string name){
            this->chainName = name;
        }

        void setBlockId(string id){
            this->blockId = id;
        }

        string getChainName(){
            return this->chainName;
        }

        string getBlockId(){
            return this->blockId;
        }

        static Request* createRequest(string method, string url, string data);
        
    protected:
        /* protected members */
        RequestType type;

    private:
        /* private methods */
        static vector<string> getPathListFromUrl(string url);

        /* private members */
        string chainName;
        string blockId;
};
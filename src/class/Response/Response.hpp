#include <iostream>
using namespace std;

#pragma once


class Response {
    public:
        Response(){
            this->status = 400;
        }

        string getJson(){
            return "";
        };

        /* sets the status as int using HTTP status codes:
            https://en.wikipedia.org/wiki/List_of_HTTP_status_codes */
        void setStatus(int value){
            this->status = value;
        }

        /* returns the status int using HTTP status codes */
        int getStatus(){
            return this->status;
        }

        /* sets the chain for this response */
        void setChain(void* requestChain){
            this->chain = requestChain;
        }

        /* adds a new block to the response set */
        void addBlock(void* newBlock){
            this->blockList.push_back(newBlock);
        }

    protected:
        /* protected members */
        int status;
        void* chain;
        vector<void*> blockList;
};
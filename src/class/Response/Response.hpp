#include <iostream>
#include <sstream>
#include "json/json.h"
using namespace std;

#pragma once


class Response {
    public:
        Response(){
            this->status = 400;
        }

        /* returns response as json string */
        string getJson(){
            Json::Value resultObject(Json::objectValue);
            resultObject["status"] = this->status;
            resultObject["chain"] = this->chainName;

            /* write the array with all blocks */
            Json::Value list(Json::arrayValue);
            for(int b=0; b<this->blockList.size(); b++){
                /* parse the block and add as json object */
                Json::Value blockValue;
                istringstream jsonBlockStream(blockList[b]);
                jsonBlockStream >> blockValue;
                list.append(blockValue);
            }
            resultObject["blockList"] = list;

            Json::StreamWriterBuilder writerBuilder;
            writerBuilder["indentation"] = "\t";
            string result = Json::writeString(writerBuilder, resultObject);

            return result;
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
        void setChain(string requestChain){
            this->chainName = requestChain;
        }

        /* adds a new block to the response set */
        void addBlock(string newBlock){
            this->blockList.push_back(newBlock);
        }

    protected:
        /* protected members */
        int status;
        string chainName;
        vector<string> blockList;
};
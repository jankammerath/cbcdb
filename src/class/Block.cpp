#include <iostream>
#include <sstream>

#include "json/json.h"
#include "Block.hpp"
#include "Crypto.hpp"

using namespace std;

/* instanciates this block */
Block::Block(string blockContent){
    /* set the current timestamp as creation time */
    this->created = time(NULL);
    this->content = blockContent;
    this->hash = Crypto::getSHA512(blockContent);
}

/* parses a block's json representation into
    a block object and returns a pointer to it  */
Block* Block::parse(string jsonText){
    Block* result;

    /* open the json document */
    Json::Value value;
    Json::CharReaderBuilder reader;
    std::istringstream jsonStream(jsonText);
    bool valid = Json::parseFromStream(reader,jsonStream,&value,NULL);
    if(valid == true){
        /* json is valid, get attributes and instance block */
        result = new Block(value["content"].asString());
        result->setIndex(value["index"].asString());
        result->setCreated(value["created"].asInt());
    } 

    return result;
}

/* returns this block as json object */
string Block::getJson(){
    return "{\"index\": \"" + this->index + "\","
            + "\"hash\": \"" + this->hash + "\","
            + "\"created\":" + std::to_string(this->created) + ","
            + "\"content\": " + this->content + "}";
}
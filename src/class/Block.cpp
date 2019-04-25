#include <iostream>
#include <sstream>

#include "json/json.h"
#include "Block.hpp"

using namespace std;

/* instanciates this block */
Block::Block(string blockContent){
    /* set the current timestamp as creation time */
    this->created = time(NULL);
    this->setContent(blockContent);
}

/* parses a block's json representation into
    a block object and returns a pointer to it  */
Block* Block::parse(string jsonText){
    Block* result;

    /* open the json document */
    Json::Value value;
    istringstream jsonStream(jsonText);
    jsonStream >> value;
    result = new Block(value["content"].asString());
    result->setIndex(value["index"].asString());
    result->setCreated(value["created"].asInt());

    return result;
}

/* returns this block as json object */
string Block::getJson(){
    /* build the json value object */
    Json::Value resultObject(Json::objectValue);
    resultObject["index"] = this->getIndex();
    resultObject["hash"] = this->getHash();
    resultObject["created"] = this->created;
    resultObject["content"] = this->getContent();

    /* write the json string */
    Json::StreamWriterBuilder writerBuilder;
    writerBuilder["indentation"] = "\t";
    string result = Json::writeString(writerBuilder, resultObject);

    return result;
}
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

/* returns this block as json object */
string Block::getJson(){
    return "{\"index\": \"" + this->index + "\","
            + "\"hash\": \"" + this->hash + "\","
            + "\"created\":" + std::to_string(this->created) + ","
            + "\"content\": " + this->content + "}";
}
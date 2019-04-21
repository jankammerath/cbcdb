#include "Block.hpp"
#include "Crypto.hpp"

using namespace std;

Block::Block(string blockContent){
    /* set the current timestamp as creation time */
    this->created = time(NULL);
    this->content = blockContent;
    this->hash = Crypto::getSHA512(blockContent);
}

void Block::store(){
    
}
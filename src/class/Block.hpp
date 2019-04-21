#include <iostream>
using namespace std;

#pragma once

class Block {
    public:
        /* public methods */
        string getHash(){ return this->hash; };
        string getIndex(){ return this->index; };
        void setIndex(string indexValue){ this->index = indexValue; };
        void setContent(string contentValue){ this->content = contentValue; };
        string getJson();
        static Block* create(string content);

    private:
        /* private members */
        string hash;
        string index;
        string content;
};
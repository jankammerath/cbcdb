#include <iostream>
using namespace std;

#pragma once

class Block {
    public:
        /* public methods: constructor */
        Block(string content);

        /* public methods: get */
        string getHash(){ return this->hash; };
        string getIndex(){ return this->index; };
        string getContent() { return this->content; };
        string getJson();

        /* public methods: set */
        void setIndex(string indexValue){ this->index = indexValue; };
        void setContent(string contentValue){ this->content = contentValue; };

    private:
        /* private members */
        string hash;
        string index;
        string content;
        int created;
};
#include <iostream>
#include "Crypto.hpp"
using namespace std;

#pragma once

class Block {
    public:
        /* public methods: constructor */
        Block(string content);

        /* public methods: get */
        string getHash(){ return Crypto::getSHA512(Crypto::decodeBase64(this->content)); };
        string getIndex(){ return this->index; };
        string getContent() { return this->content; };
        string getJson();

        /* public methods: set */
        void setIndex(string indexValue){ this->index = indexValue; };
        void setContent(string contentValue){ this->content = Crypto::encodeBase64(contentValue); };
        void setCreated(int timestamp){ this->created = timestamp; };

        /* public static methods */
        static Block* parse(string jsonText);

    private:
        /* private members */
        string index;
        string content;
        int created;
};
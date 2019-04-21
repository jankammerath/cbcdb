#include <iostream>
#include "Storage.hpp"
using namespace std;

#pragma once

class Block {
    public:
        string getHash(){
            return this->hash;
        }

    private:
        string hash;
};
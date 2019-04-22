#include <iostream>
#include <vector>
#include "Storage.hpp"
#include "Block.hpp"
using namespace std;

#pragma once

class Chain {
    public:
        Chain(Storage* chainStorage, string name);
        string getName();
        vector<string> getBlockIdList();
        Block* getBlockById(string blockId);
        Block* insert(string content);
        static Chain* create(Storage* chainStorage, string name);

    private:
        string name;
        Storage* storage;
};
#include <iostream>
#include "Storage.hpp"
using namespace std;

#pragma once

class Chain {
    public:
        Chain(Storage* chainStorage, string name);
        string getName();
        static Chain* create(Storage* chainStorage, string name);

    private:
        string name;
        Storage* storage;
};
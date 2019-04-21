#include <iostream>
using namespace std;
#include "Chain.hpp"
#include "FileSystem.hpp"

Chain::Chain(Storage* chainStorage, string name){
    this->storage = chainStorage;
    this->name = name;
}

string Chain::getName(){
    return this->name;
}

/* returns a vector with all blocks in the chain
    ordered by the creation date */
vector<Block> Chain::getBlockList(){
    vector<Block> result;



    return result;
}

/* the head index is a SHA512 hash of all previous
    head indices. The first head index is the SHA512
    hash of the first block created */
string Chain::getHeadIndex(){
    string result = "";

    return result;
}

/* creates a new chain on the defined storage */
Chain* Chain::create(Storage* chainStorage, string name){
    Chain* result;

    /* define the path of the storage */
    string chainPath = chainStorage->getStoragePath() + "/chain/" + name;
    if(!FileSystem::fileExists(chainPath)){
        bool created = FileSystem::makeDir(chainPath);
        if(created == true){
            /* chain successfully created */
            cout << "Chain " << name << " created in " << chainPath << endl;
        }
    }

    return result;
}
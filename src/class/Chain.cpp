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
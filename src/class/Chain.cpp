#include <iostream>
using namespace std;
#include "Chain.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"

Chain::Chain(Storage* chainStorage, string name){
    this->storage = chainStorage;
    this->name = name;
}

string Chain::getName(){
    return this->name;
}

/* returns a vector with all blocks in the chain
    ordered by the creation date */
vector<Block*> Chain::getBlockList(){
    vector<Block*> result;

    /* get all files in the storage path */
    vector<string> fileList = FileSystem::getDirectoryFileList
            (this->storage->getStoragePath() + "/chain/" + name + "/block");
    for(int f=0; f<fileList.size(); f++){
        cout << "Block file: " << fileList[f] << endl;
    }

    return result;
}

/* inserts a new block into the chain */
Block* Chain::insert(string content){
    Block* result;

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
            Logger::write("Chain <" + name + "> created in: " + chainPath);

            /* create the dir for the blocks */
            FileSystem::makeDir(chainPath + "/block");
        }
    }

    return result;
}
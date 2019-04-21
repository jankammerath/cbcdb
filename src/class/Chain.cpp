#include <iostream>
using namespace std;
#include "Chain.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"
#include "Crypto.hpp"

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

/* inserts a new block into the chain:
    This is also where the core functionality of
    the blockchain resides as it calculates each
    blocks hash out of the hashes of the previous 
    blocks with which it creates the "block chain" */
Block* Chain::insert(string content){
    Block* result = new Block(content);

    /* calculate the index for this block */
    string indexBaseValue = "";
    vector<Block*> blockList = this->getBlockList();
    for(int b=0; b<blockList.size(); b++){
        indexBaseValue.append(blockList[b]->getIndex());
    }
    result->setIndex(Crypto::getSHA512(indexBaseValue));

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
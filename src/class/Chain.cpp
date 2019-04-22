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
vector<string> Chain::getBlockIdList(){
    vector<string> result;

    /* get all files in the storage path */
    string dirName = this->storage->getStoragePath() + "/chain/" + this->getName() + "/block";
    vector<string> fileList = FileSystem::getDirectoryFileList(dirName);
    for(int f=0; f<fileList.size(); f++){
        if(fileList[f] != ".." && fileList[f] != "."){
            /* this is an acrtual block */
            result.push_back(fileList[f]);
        }
    }

    return result;
}

/* returns a pointer to a single block identified by its block id */
Block* Chain::getBlockById(string blockId){
    Block* result;

    /* check if the block exists on disk */
    string blockPath = this->storage->getStoragePath() + "/chain/"
                        + this->getName() + "/block/" + blockId;
    if(FileSystem::fileExists(blockPath)){
        /* block exists on disk, load it */
        string blockString = FileSystem::readFile(blockPath);
        result = Block::parse(blockString);
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
    vector<string> blockIdList = this->getBlockIdList();
    for(int b=0; b<blockIdList.size(); b++){
        indexBaseValue.append(blockIdList[b]);
    }
    result->setIndex(Crypto::getSHA512(indexBaseValue));

    /* flush the block to storage */
    string blockFileName = this->storage->getStoragePath() 
            + "/chain/" + name + "/block/" + result->getIndex();
    FileSystem::writeFile(blockFileName,result->getJson());

    return result;
}

/* creates a new chain on the defined storage */
Chain* Chain::create(Storage* chainStorage, string name){
    Chain* result = new Chain(chainStorage,name);

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
#include <iostream>
#include "Storage.hpp"
#include "FileSystem.hpp"
using namespace std;

Storage::Storage(string storagePath){
    this->path = storagePath;
}

void Storage::execute(GetRequest request){
    
}

bool Storage::chainExists(string chainName){
    return FileSystem::fileExists(this->path + "/" + chainName);
}
/* include standard libraries */
#include <iostream>
#include <unistd.h>
#include <libconfig.h++>

/* define namespaces */
using namespace std;
using namespace libconfig;

/* include customer header files */
#include "class/FileSystem.hpp"
#include "class/Logger.hpp"
#include "class/Service.hpp"

/* determines which config file to use and returns its path */
string getConfigFile(){
    string result = "./cbcdb.conf";

    string fileList[] = {"./cbcdb.conf","./bin/cbcdb.conf","/etc/cbcdb.conf"};
    for(const string &filePath : fileList){
        if(FileSystem::fileExists(filePath)){
            result = filePath;
        }
    }

    return result;
}

int main() {
    /* create config instance */
    Config cfg;

    /* open the main configuration file */
    try{
        /* read the configuration file */
        string configFile = getConfigFile();
        Logger::write("Config file: " + configFile);
        cfg.readFile(configFile.c_str());
    }catch(const FileIOException &fioex){
        /* flush any i/o error into stderr */
        Logger::writeError("I/O error while config reading file.");
        return(EXIT_FAILURE);
    }catch(const ParseException &pex){
        /* flush any parser error into stderr */
        Logger::writeError("Parse error at " + (string)pex.getFile() 
                            + ":" + std::to_string(pex.getLine())
                            + " - " + pex.getError());
        return(EXIT_FAILURE);
    }

    /* get the required configuration for the service */
    int servicePort = 8080;
    string storagePath = "./data";
    const Setting& root = cfg.getRoot();
    root.lookupValue("port",servicePort);
    root.lookupValue("storagePath",storagePath);

    /* create an instance of the service */
    Service* service = new Service(servicePort,storagePath);
    Logger::write("This service is: " + service->getName());

    /* start the service */
    service->start();
    Logger::write("Service started on TCP port " + service->getName());

    /* launch the service and wait until it terminates */
    while(service->isTerminated() == false){ sleep(1); }

    /* notify stdout of termination */
    Logger::write("Service terminated");
    
    return 0;
}
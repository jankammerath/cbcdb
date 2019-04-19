#include <iostream>
#include <sys/stat.h>
using namespace std;

class FileSystem {
    public:
        static bool fileExists(string name){
            struct stat buffer;   
            return (stat (name.c_str(), &buffer) == 0);     
        }
}
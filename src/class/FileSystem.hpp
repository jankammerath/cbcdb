#include <iostream>
#include <sys/stat.h>
using namespace std;

class FileSystem {
    public:
        /* returns true when a file exists, otherwise false */
        static bool fileExists(string name){
            struct stat buffer;   
            return (stat (name.c_str(), &buffer) == 0);     
        }

        /* creates a directory using unix 'mkdir' equivalent */
        bool makeDir(string path){
            bool result = false;

            int status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            if(status != 0){
                /* error creating the directory */
                cout << "Failed to create path: " << path << endl;
            }else{
                /* successfully created directory */
                result = true;
            }

            return result;
        }
};
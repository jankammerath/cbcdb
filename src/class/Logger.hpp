#include <iostream>
using namespace std;

class Logger {
    public:
        static void write(string text){
            cout << text << endl;
        }

        static void writeError(string text){
            std::cerr << text << endl;
        }
};
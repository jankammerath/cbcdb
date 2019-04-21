#include <iostream>
using namespace std;

#pragma once

class Logger {
    public:
        static void write(string text){
            cout << text << endl;
        }

        static void writeError(string text){
            std::cerr << text << endl;
        }
};
#include <iostream>
using namespace std;

#include "Request/GetRequest.hpp"

class Storage {
    public:
        /* public methods */
        Storage(string storagePath);
        void execute(GetRequest request);

    private:
        /* private methods */
        bool chainExists(string chainName);

        /* private members */
        string path;
};
#include <iostream>
using namespace std;

#include "Request/GetRequest.hpp"
#include "Response/GetResponse.hpp"

class Storage {
    public:
        /* public methods */
        Storage(string storagePath);
        GetResponse* execute(GetRequest* request);
        Response* execute(Request* request);

    private:
        /* private methods */
        bool chainExists(string chainName);

        /* private members */
        string path;
};
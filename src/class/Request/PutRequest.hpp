#include <iostream>
#include "Request.hpp"
using namespace std;

class PutRequest : public Request {
    public:
        PutRequest() : Request() {
            this->type = PUT;
        };
};
#include <iostream>
#include "Request.hpp"
using namespace std;

class GetRequest : public Request {
    public:
        GetRequest() : Request() {
            this->type = GET;
        };
};
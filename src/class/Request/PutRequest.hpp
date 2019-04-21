#include <iostream>
#include "Request.hpp"
using namespace std;

#pragma once

class PutRequest : public Request {
    public:
        PutRequest() : Request() {
            this->type = PUT;
        };
};
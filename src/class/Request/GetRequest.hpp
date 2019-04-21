#include <iostream>
#include "Request.hpp"
using namespace std;

#pragma once

class GetRequest : public Request {
    public:
        GetRequest() : Request() {
            this->type = GET;
        };
};
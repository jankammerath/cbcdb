#include <iostream>
#include "Response.hpp"
using namespace std;

#pragma once

class GetResponse : public Response {
    public:
        GetResponse() : Response() {
            this->status = 404;
        };
};
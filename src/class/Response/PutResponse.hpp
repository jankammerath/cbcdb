#include <iostream>
#include "Response.hpp"
using namespace std;

class PutResponse : public Response {
    public:
        PutResponse() : Response() {
            this->status = 404;
        };
};
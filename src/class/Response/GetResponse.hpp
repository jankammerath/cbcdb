#include <iostream>
#include "Response.hpp"
using namespace std;

class GetResponse : public Response {
    public:
        GetResponse() : Response() {
            this->status = 404;
        };
};
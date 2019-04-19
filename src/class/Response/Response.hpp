#include <iostream>
using namespace std;

#pragma once

class Response {
    public:
        Response(){
            this->status = 400;
        }

        string getJson(){
            return "";
        };

        /* sets the status as int using HTTP status codes:
            https://en.wikipedia.org/wiki/List_of_HTTP_status_codes */
        void setStatus(int value){
            this->status = value;
        }

        /* returns the status int using HTTP status codes */
        int getStatus(){
            return this->status;
        }

    protected:
        /* protected members */
        int status;
};
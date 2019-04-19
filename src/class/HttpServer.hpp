#include <iostream>
#include <microhttpd.h>
using namespace std;

class HttpServer {
    public:
        HttpServer();
        void start();

    private:
        int port;
        struct MHD_Daemon* d;
};
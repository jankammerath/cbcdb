#include <iostream>
#include <microhttpd.h>
using namespace std;

class HttpServer {
    public:
        HttpServer(int serverPort);
        void start();
        void stop();

    private:
        int port;
        struct MHD_Daemon* d;
};
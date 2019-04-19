using namespace std;
#include "HttpServer.hpp"

class Service {
    public:
        Service(int servicePort);
        string getName();
        bool isTerminated();
        bool start();
        static void handleRequest(string method, string url, string data);

    private:
        bool terminated;
        int port;
        HttpServer* server;
};
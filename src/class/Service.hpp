using namespace std;
#include "HttpServer.hpp"
#include "Storage.hpp"

class Service {
    public:
        Service(int servicePort, string storagePath);
        string getName();
        bool isTerminated();
        bool start();
        static string handleRequest(string method, string url, string data);

    private:
        bool terminated;
        HttpServer* server;
};
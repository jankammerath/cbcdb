using namespace std;
#include "HttpServer.hpp"
#include "Storage.hpp"

class Service {
    public:
        /* public methods */
        Service(int servicePort, string storagePath);
        string getName();
        bool isTerminated();
        bool start();

        /* static public methods */
        static HttpResult handleRequest(string method, string url, string data);
        static void setInstance(Service* newInstance);
        static Service* getInstance();
        
    private:
        /* private members */
        bool terminated;
        HttpServer* server;
        Storage* storage;

        /* static private members */
        static Service* instanceRef;
};
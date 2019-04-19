#include <iostream>
#include <microhttpd.h>
using namespace std;

struct HttpResult {
    int status;
    string content;
};

class HttpServer {
    public:
        HttpServer(int serverPort, void* requestHandler);
        void start();
        void stop();
        bool isActive();
        static int handleRequest(void * cls,
		    struct MHD_Connection * connection,
		    const char * url, 
		    const char * method,
            const char * version,
		    const char * upload_data,
		    size_t * upload_data_size,
            void ** ptr);

    private:
        int port;
        void* handler;
        struct MHD_Daemon* daemonHandle;
};
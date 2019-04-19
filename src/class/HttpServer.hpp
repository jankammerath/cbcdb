#include <iostream>
#include <microhttpd.h>
using namespace std;

class HttpServer {
    public:
        HttpServer(int serverPort);
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
        struct MHD_Daemon* daemonHandle;
};
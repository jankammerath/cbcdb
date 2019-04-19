using namespace std;

class Service {
    public:
        Service(int servicePort);
        string getName();
        bool isTerminated();
        bool start();

    private:
        bool terminated;
        int port;
};
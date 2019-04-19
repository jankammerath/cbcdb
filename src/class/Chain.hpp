#include <iostream>
using namespace std;

class Chain {
    public:
        Chain(bool internal);
        string getName();

    private:
        string name;
        string uuid;
        bool isInternal;
};
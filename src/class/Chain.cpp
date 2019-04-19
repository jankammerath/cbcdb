#include <iostream>
using namespace std;
#include "Chain.hpp"

Chain::Chain(bool internal){
    /* user data and other things to manage
        core functinality of the database
        are also stored using the database
        itself as internal chains */
    this->isInternal = internal;
}
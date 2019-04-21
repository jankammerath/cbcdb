#include <iostream>
#include <microhttpd.h>
#include <cstring>
#include <sstream>
using namespace std;

class Util{
    public:
        static string escapeJsonString(const string& input){
            std::ostringstream ss;
            for (auto iter = input.cbegin(); iter != input.cend(); iter++) {
                switch (*iter) {
                    case '\\': ss << "\\\\"; break;
                    case '"': ss << "\\\""; break;
                    case '/': ss << "\\/"; break;
                    case '\b': ss << "\\b"; break;
                    case '\f': ss << "\\f"; break;
                    case '\n': ss << "\\n"; break;
                    case '\r': ss << "\\r"; break;
                    case '\t': ss << "\\t"; break;
                    default: ss << *iter; break;
                }
            }
            return ss.str();
        };
}
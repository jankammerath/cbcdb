#include <iostream>
#include <cstring>
#include <openssl/sha.h>

#pragma once

using namespace std;

class Crypto {
    public:
        /* generates a SHA512 hash for the text param and returns it as string */
        static string getSHA512(string text){
            string result = "";

            unsigned char digest[SHA512_DIGEST_LENGTH];   
            const char* cstr_text = text.c_str(); 
            SHA512((unsigned char*)cstr_text, strlen(cstr_text), (unsigned char*)&digest);    
            char mdString[SHA512_DIGEST_LENGTH*2+1];
 
            for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
                sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
            }

            result.assign(mdString);

            return result;
        }
};
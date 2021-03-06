#include <iostream>
#include <cstring>
#include <openssl/sha.h>

#pragma once

using namespace std;

static const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz"
                                    "0123456789+/";

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

        static bool isBase64(unsigned char c) {
            return (isalnum(c) || (c == '+') || (c == '/'));
        }

        /* encodes a string to a base64 string */
        static string encodeBase64(string text){
            string ret;
            int i = 0;
            int j = 0;
            unsigned char char_array_3[3];
            unsigned char char_array_4[4];
            int in_len = text.length();
            const char* bytes_to_encode = text.c_str();

            while (in_len--) {
                char_array_3[i++] = *(bytes_to_encode++);
                if (i == 3) {
                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for(i = 0; (i <4) ; i++)
                    ret += base64_chars[char_array_4[i]];
                i = 0;
                }
            }

            if (i)
            {
                for(j = i; j < 3; j++)
                char_array_3[j] = '\0';

                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (j = 0; (j < i + 1); j++)
                ret += base64_chars[char_array_4[j]];

                while((i++ < 3))
                ret += '=';

            }

            return ret;           
        }

        /* decodes a base64 string to a string */
        static string decodeBase64(string encodedString){
            int in_len = encodedString.size();
            int i = 0;
            int j = 0;
            int in_ = 0;
            unsigned char char_array_4[4], char_array_3[3];
            std::string ret;

            while (in_len-- && ( encodedString[in_] != '=') && Crypto::isBase64(encodedString[in_])) {
                char_array_4[i++] = encodedString[in_]; in_++;
                if (i ==4) {
                for (i = 0; i <4; i++)
                    char_array_4[i] = base64_chars.find(char_array_4[i]);

                char_array_3[0] = ( char_array_4[0] << 2       ) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) +   char_array_4[3];

                for (i = 0; (i < 3); i++)
                    ret += char_array_3[i];
                i = 0;
                }
            }

            if (i) {
                for (j = 0; j < i; j++)
                char_array_4[j] = base64_chars.find(char_array_4[j]);

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);

                for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
            }

            return ret;            
        }
};
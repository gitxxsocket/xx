//
//

#pragma once


#include <string>
#include <openssl/des.h>

class XCrypt {
public:
    bool Init(std::string password);
    int Encrypt(const char *in_data, int insize, char *out_data, bool is_end = false);
    int Decrypt(const char *in_data, int insize, char *out_data, bool is_end = false);
private:
    DES_key_schedule key_sch_;
};
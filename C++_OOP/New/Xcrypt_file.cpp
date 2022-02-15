//
//



#include <iostream>
#include "xcrypt.h"
#include <memory_resource>

using namespace std;

int main(int argc, char* argv[])
{



    //
    XCrypt crypt;
    crypt.Init("12345678");
    char out[1024] = { 0 };
    int en_size = crypt.Encrypt("abcdefgh", 8, out, true);
    cout << "en_size = " << en_size << endl;
    cout << out << endl;
    char de_out[1024] = { 0 };
    int de_size = crypt.Decrypt(out, en_size, de_out, true);
    cout << de_size<<":de_out=" << de_out << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}


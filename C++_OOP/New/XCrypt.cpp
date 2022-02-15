
#include "xcrypt.h"
#include <iostream>
#include <cstring>
using namespace std;
///³õÊ¼»¯ÃØÔ¿,DES¼ÓÃÜËã·¨ ÃØÔ¿×î¶à8Î» ¶àÓà¶ªÆú²»×ã²¹0
bool XCrypt::Init(std::string password)
{
    const_DES_cblock key = { 0 }; //²»×ã²¹0
    int key_size = password.size();
    if (key_size > sizeof(key)) //¶àÓà¶ªÆú
    {
        key_size = sizeof(key);
    }
    memcpy(key, password.c_str(), key_size);
    DES_set_key(&key, &key_sch_);
    return true;
}



int XCrypt::Encrypt(const char* in_data, int insize, char* out_data, bool is_end)
{
    if (!in_data || insize <= 0|| !out_data) return 0;
    int write_size = 0;
    const_DES_cblock in = { 0 };    //ÊäÈëÊý¾Ý
    DES_cblock out = { 0 };         //Êä³ö
    const int block_size = sizeof(const_DES_cblock);
    int data_size = 0;
    int padding = block_size - insize % block_size;


    for (int i = 0; i < insize; i += block_size)
    {
        if (insize - i < block_size)
        {
            data_size = insize - i;
        }
        else
        {
            data_size = block_size;
        }

        //¸´ÖÆÊý¾ÝÔ´
        memcpy(in, in_data + write_size, data_size);

        //Ìî³ä ²¹³äµÄÊý¾Ý´óÐ¡  @@@@@@@1   @@@55555 @@@@@@@@8888888
        if (is_end && i + block_size >= insize) //´¦Àí×îºóÒ»¿éÊý¾Ý
        {
            //@@@@@@@@8888888
            if (padding == block_size)
            {
                DES_ecb_encrypt(&in, &out, &key_sch_, DES_ENCRYPT);
                memcpy(out_data + write_size, &out, block_size);
                write_size += block_size;
                memset(in, padding, sizeof(in)); //Ìî³ä8
            }
                //@@@@@@@1   @@@55555
            else
            {
                memset(in + insize % block_size, padding, padding);
            }

        }

        //¼ÓÃÜÊý¾Ý
        DES_ecb_encrypt(&in, &out, &key_sch_, DES_ENCRYPT);
        memcpy(out_data + write_size, &out, block_size);

        write_size += block_size;
    }
    return write_size;
}


int XCrypt::Decrypt(const char* in_data, int insize, char* out_data, bool is_end )
{
    if (!in_data || insize <= 0 || !out_data) return 0;
    int write_size = 0;
    const_DES_cblock in = { 0 };    //ÊäÈëÊý¾Ý
    DES_cblock out = { 0 };         //Êä³ö
    const int block_size = sizeof(const_DES_cblock);
    int data_size = 0;
    for (int i = 0; i < insize; i += block_size)
    {
        memcpy(in, in_data + write_size, block_size);

        //½âÃÜ
        DES_ecb_encrypt(&in, &out, &key_sch_, DES_DECRYPT);
        data_size = block_size;
        //´¦Àí½áÎ²Ìî³ä @@@55555 @@@@@@@@8888888
        if (is_end && insize - i <= block_size)
        {
            data_size = block_size - out[7];
            if (data_size == 0)
            {
                break;
            }
            else if (data_size < 0)
            {
                cerr << "Decrypt failed!padding size error!" << endl;
                break;
            }
        }
        memcpy(out_data + write_size, &out, data_size);
        write_size += data_size;
    }
    return write_size;
}
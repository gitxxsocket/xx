#include <stdio.h>
#include <string.h>
#include "smart_ptr.h"


int main(int argc, char const *argv[])
{

    int table[2][3]=
    {
       {1,3,5},    
       {2,4,6}     
    };
    
    for (int *start =&table[0][0],*end=&table[1][2];start <= end;start++)
    {
        printf("%d \n",*start);
    }
    

    return 0;
}
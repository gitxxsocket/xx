#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smart_ptr.h"


char* String(int len){
    char *s = ( char *)malloc(len);
    return s;
}


int main(int argc, char const *argv[])
{
   char *str = String(1024);
   strncpy(str,"xxxxxxxxxxxxxxxxxx",100);
    printf("%s \n",str);
    free(str);
    return 0;
}

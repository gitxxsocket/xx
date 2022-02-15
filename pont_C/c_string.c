#include <stdio.h>
#include <string.h>
#include "smart_ptr.h"


int main(void) {

    char str[20];
    memset(str, 0, sizeof(str));
    printf("str %p \n",&str);
    printf("str %d \n",sizeof(str));

    //strlen
    char str1[] = "hello world!";
    printf("str1 %p \n",&str1);
    printf("str1 %d \n",sizeof(str1));
    printf("str1 %d \n",strlen(str1));

    

   //strncpy
   char str6[1024] = {0};
   strncpy(str6,"xxxxxxxxxxxx",sizeof(str6)-1);

   //strncat
   char str8[1024] ="hello";
    strncat(str8,"world!",sizeof(str8)/sizeof(char)-strlen(str8));
    printf("str8 %d \n",sizeof(str8));
    printf("str8 %s \n",str8);


    //strcmp
    char str3[] = "hello";
    char str4[] = "world";
   printf( strcmp(str3,str4));

    return 0;
}
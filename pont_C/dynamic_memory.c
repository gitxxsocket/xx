#include "smart_ptr.h"
#include <stdio.h>
#include <string.h>

typedef int (*Calc)(int, int);

struct Buffer {
  int len;
  char *data;
};

 //柔性数组
 struct Buffer1 {
  int len;
  char data[];
};

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

void calculate(int a, int b, Calc proc) {
  printf("result = %d \n", proc(a, b));
}
int main(int argc, char const *argv[]) {
  int (*p)(int, int);
  p = &add;
  p(1, 3);

  calculate(10, 5, sub);

  short num = 128;
  char *PChar = (char *)&num;
  char *pInt = (int *)&num;

  //
  struct Buffer *buf = (struct Buffer *)malloc(sizeof(struct Buffer));
  if (buf != NULL) {
    buf->data = malloc(sizeof(char) * 1024);
  }

  //柔性数组
struct Buffer *buf1 = (struct Buffer *)malloc(sizeof(struct Buffer1) +sizeof(char)*1024);


  return 0;
}
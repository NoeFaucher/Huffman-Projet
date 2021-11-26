#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coder.h"

//#define SAMPLE " etaonihsrldumcwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char const *argv[]) {

  char* path = "lorem.txt";

  if (!coder(path)){
    return -1;
  }



  return 0;
}

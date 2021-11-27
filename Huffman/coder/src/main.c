#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coder.h"
#include "decoder.h"

//#define SAMPLE " etaonihsrldumcwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char const *argv[]) {

  char* path_file = "h2g2.txt";
  char* path_hfzip = "h2g2.hfzip";

  //printf("\\");

  if (!coder(path_file,path_hfzip)){
    return -1;
  }



  return 0;
}

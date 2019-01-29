#include "string.h"
#include <cstdio>
#include <cstdlib>

// string function test code

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("call: %s <word>\n", argv[0]);
    exit(1);
  }

  printf("vowel_count = %d\n", vowel_count(argv[1]));
  printf("empty = %d\n", empty(argv[1]));

  to_upper(argv[1]);  
  printf("to_upper = %s\n", argv[1]);

  print_os();
  printf("\n");
  return 0;
}

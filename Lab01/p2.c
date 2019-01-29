#include <stdio.h>

int main()
{
  int x = 24; //use different values to test your program
  int j = 2;
  int div_count = 0;

  while (j < x) {
    if (x % j == 0) { //added the '=='
      div_count++;
      j++; //added this line to increment
    }
    else
      j++; //added the else statment to increment
  }

  printf("%d can be divided by %d numbers\n", x, div_count); //changed j to div_count
  
  return 0; //added the return statement
}

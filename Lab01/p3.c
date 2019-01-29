#include <stdio.h>

int main() {

  unsigned int y = 18;
  float count = 1;
  float x = (float) y; //both count and x were used as floats to prevent errors due to truncating nature of int type

  while (count <=  x) {
    if (y == 1) { //if y is entered as 1 (considering 1 a perfect square)
      printf("yes\n");
      break;
    }
    else if (x / count == count) { //finds if it is a square
      printf("yes\n");
      break;
    }
    else
      count++;
  }

  if (count > x)    //to see if loop finished without finding a result
    printf("no\n");
  
  return 0;
}

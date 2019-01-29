#include <stdio.h>

int main()
{
  int val_max =   1000;
  int count1 =  2;
  int count2 = 2; //two count variables were required to keep track of both while loops
  int numberOfPrimes = 0;

  while (count1 <= val_max) {
    count2 = 2; //value of count2 is reset to 2 everytime count1 has a new value
    
    while (count2 < count1) {
      if (count1 % count2 == 0)
	break;
      else
	count2++;
    }

    if (count2 == count1)
      numberOfPrimes++; //increments because a number was found which was not divisible
    
    count1++;
  }

  printf("%d\n", numberOfPrimes);

  return 0;
}

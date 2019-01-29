#include <stdio.h>

#ifdef BIG_ENDIAN //check for big or little endian machine
    #define big_endian 1
#else
    #define big_endian 0
#endif

//returns the number of 0-bits in x
int count_zeroes(unsigned int x)
{
    if (x == 0) //if 0 was entered then return 1
        return 1;

    int count = 0;
    while ( x > 0 ) {
        if ( x % 2 == 0 )
        count++;
        x = x / 2;
    }
    return count;
}

//helper function to to_low_order_byte_first
//prints str in big endian order
void print_big_endian(char* str) {
    char reverse[8];
    for (int i = 0; i < 8; i++)
        reverse[i] = str[7 - i]; //reverses the input array

    printf("%c%c %c%c %c%c %c%c ", reverse[0], reverse[1], reverse[2],
            reverse[3], reverse[4], reverse[5], reverse[6], reverse[7]);
}

//helper function to to_low_order_byte_first
//prints str in little endian order
void print_little_endian(char* str) {
    char reverse[8];
    for (int i = 0; i < 8; i++)
        reverse[i] = str[7 - i]; //reverses the input array

    //this function is identical to print_big_endian
    //except forthe following 2 lines
    printf("%c%c %c%c %c%c %c%c ", reverse[6], reverse[7], reverse[4],
            reverse[5], reverse[2], reverse[3], reverse[0], reverse[1]);
}

//that converts A, which contains n unsigned int numbers,
//into low-order-byte-first format
void to_low_order_byte_first(unsigned int A[], int n)
{
    int remainder, str_index = 0;
    char str[8], c;

    for (int i = 0; i < n; i++) {
        remainder = A[i] % 16;

        if (remainder < 10) { //if remainder is a single number
            c = (char) remainder + 48;
            str[str_index] = {c};
        } else { // if remainder is between 10-15
            c = (char) remainder + 55;  // a char of A to F is assigned
            str[str_index] = {c};
        }
        A[i] = A[i] / 16;
        str_index++;

        if(A[i] != 0)   // if number still has a remainder then repeat the loop
            i--;
        else {  // if number has reached zero
            while(str_index != 8) {     //fill up the remaining blanks
                str[str_index] = 48;
                str_index++;
            }
            //print in the same format as a little/big endian machine
            if (big_endian == 1) {
                print_big_endian(str);
                str_index = 0;
            } else {
                print_little_endian(str);
                str_index = 0;
    }   }   }
}

//test functions count_zeroes and to_low_order_byte_first
int main()
{
    printf("Testing count_zeroes...\n");
    printf("count_zeroes(155): %d\n", count_zeroes(155));
    printf("\n");
    printf("Testing to_low_order_byte_first....\n");
    if(big_endian == 1)
        printf("Machine order: Big Endian\n");
    else
        printf("Machine order: Little Endian\n");
    printf("to_low_order_byte_first( {111, 222, 333, 444, 5555, 6666, 7777, 8888, 9999} ): ");
    unsigned int A[] = {111, 222, 333, 444, 5555, 6666, 7777, 8888, 9999};
    to_low_order_byte_first(A, 9);
    printf("\n");
    printf("\n");
    printf("to_low_order_byte_first( {9999, 8888, 7777, 6666, 5555, 444, 333, 22, 11} ): ");
    unsigned int B[] = {999999999, 8888, 7777, 6666, 55555, 444, 333, 22, 11};
    to_low_order_byte_first(B, 9);
    printf("\n");

    return 0;
}

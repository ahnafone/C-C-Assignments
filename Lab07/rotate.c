#include <stdio.h>

//helper function: prints the int x into hexadecimal
void print_hex(int x) {
    int remainder1 = x % 16, remainder2 = (x/16) % 16;
    char c1, c2;

    if(remainder1 < 10)
        c1 = remainder1 + 48;
    else
        c1 = remainder1 + 87;
    if(remainder2 < 10)
        c2 = remainder2 + 48;
    else
        c2 = remainder2 + 87;

    printf("0x%c%c ", c2, c1);
}

//that rotates x to the right, i.e. all bits in x are shifted one position
//to the right, and the lowest-order bit which usually gets lost in the
//>> 1 operation reappears as highest-order bit
void rotate_right(unsigned char &x) {
    int lowest_order_bit = x % 2;
    x = x >> 1;
    if (lowest_order_bit == 1)  //if the lowest order bit is a 1
        x = x + 128;            //concat 1 to front of byte
    print_hex(x);   //helper function to print a decimal in hexadecimal
}

//that rotates all bits stored in an n byte array A one position to the
//right. We assume the lowest-order bit in A to be the lowest-order bit
//of A[n-1], and the highest-order bit of A to be highest-order bit in A[0]
void rotate_right(unsigned char A[], int n) {
    for (int i = 0; i < n; i++)
        rotate_right(A[i]);     //call rotate_right(unsigned char)
}

//tests both rotate_right functions
int main()
{
    printf("Testing rotate_right(x)...\n");
    printf("rotate_right(0x1): ");
    unsigned char num = 1;
    rotate_right(num);
    printf("\n");
    printf("rotate_right(0xc6): ");
    num = 0xc6;
    rotate_right(num);
    printf("\n");
    printf("\n");
    printf("Testing rotate_right(A[], n)...\n");
    printf("rotate_right({ 0x81, 0x45, 0x03 }, 3): ");
    unsigned char A[] = { 0x81, 0x45, 0x03 };
    rotate_right(A, 3);
    printf("\n");
    printf("rotate_right({ 0x80, 0x44, 0x02 }, 3): ");
    unsigned char B[] = { 0x80, 0x44, 0x02 };
    rotate_right(B, 3);
    printf("\n");

    return 0;
}

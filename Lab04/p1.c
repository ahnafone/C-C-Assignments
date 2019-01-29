/*
 * This is file p1.c of Lab04
 * Author: Ahnaf Ahmed 1560767
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000000     //maximum number of bytes the program with accept

int main ()
{
    //Declare variables
    char *str, c;         
    int size = 0;
    str = (char*) malloc(MAX);      //allocate memory
    
    if (str) {      //incase allocation was not successful
        printf("Enter something: ");
        scanf("%c", &c);
        while (c != '\0' && c != '\n') {
            size = size + 1;
            if (size > MAX) {       //end the program if size passes MAX
                printf("Input too long!\n");
                return 1;
            }
            str[size] = c;
            scanf("%c", &c);    //scans the next character
        }
        
        //prints the output
        for (int i = (size); i >= 0; i--) {
            printf("%c", str[i]);
        }
        printf("\n");
    }

    free(str);      //return memory
    return 0;
}

/*
 * This is file p2.c of Lab04
 * Author: Ahnaf Ahmed 1560767
 */
#include <stdio.h>
#include <string.h>

#define MAX 10000000

int main (int argc, char *argv[]) 
{
    char c;
    int size = 0;
    int numOfWords = 1, numOfLines = 1;
    
    printf("Enter something: ");
    while (scanf("%c", &c)) {
        
        if (c == '\n') {
            numOfWords++;
            numOfLines++;
        }
        else if (c == ' ')
            numOfWords++;
        size++;
    }
    
    if (size == 0) {
        printf("Empty input\n");
        return 0;
    }
    
    //if argument is -c: number of characters
    else if (argv[1] == "-c")
        printf("Number of characters: %d\n", size);
    
    //if argument is -w: number of words
    else if (argv[1] == "-w")
        printf("Number of words: %d\n", numOfWords);
    
    //if argument is -l: number of lines
    else if(argv[1] == "-l")
        printf("Number of lines: %d\n", numOfLines);
    
    return 0;
}

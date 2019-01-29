#include "string.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//detecting the Operating System
#if defined (_WIN32)
    #define OS "UNIX"
#elif defined (unix)
    #define OS "WINDOWS"
#else
    #define OS "UNKNOWN"
#endif

//convert all characters in a string s into upper case
void to_upper (char *s) {
    int size = strlen(s), num_char;
    if (size == 0)
        return;
    
    for (int i = 0; i < size; i++) {    //loops through the string
        num_char = s[i];
        if (num_char >= 97 && num_char <= 122) {
            num_char = num_char - 32;   //changes the ascii value to its
            s[i] = num_char;            //upper case version
        }
    }
}

//returns the number of vowels in a string
int vowel_count (char *s) {
    int size = strlen(s), count = 0;
    if (size == 0)
        return count;   //returns 0
    
    for (int i = 0; i < size; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || 
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || 
                s[i] == 'O' || s[i] == 'U' )
            count++;
    }
    return count;
}

//returns true if and only if a string is empty
bool empty (char *s) {
    int size = strlen(s);
    if (size == 0)
        return false;
    return true;
}

// prints the operating system the application is compiled for:
// - if macro UNIX is defined, print UNIX to stdout,
// - else if macro WINDOWS is defined, print WINDOWS,
// - otherwise, print UNKNOWN
void print_os () {
    printf(OS);
}
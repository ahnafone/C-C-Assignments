#pragma once
#include <string.h>

//to_upper: converts all characters in a string s into upper case
void to_upper (char *s);

//vowel_count: returns the number if vowels in a string
int vowel_count (char *s);

//empty: returns true if and only if a string is empty
bool empty (char *s);

//print_os: prints the operating system the application is compiled for:
// - if macro UNIX is defined, print UNIX to stdout,
// - else if macro WINDOWS is defined, print WINDOWS,
// - otherwise, print UNKNOWN
void print_os();
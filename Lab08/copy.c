#include <stdio.h>
#include <stdlib.h>

void read_write(FILE *fp_in, FILE *fp_out) {
    char c;
    int i;
    while ( (i = fgetc(fp_in)) != EOF ) {
        c = (char) i;
        fprintf(fp_out, "%c\n", c);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)  //checks for required number arguements
        { printf("Please enter only 2 arguements\n"); exit(10); }


    FILE *fp_in, *fp_out = fopen(argv[2], "w");
    if((fp_in = fopen(argv[1], "r")) == NULL)   //checks if first file exists
        { printf("File '%s' does not exist in the directory\n", argv[1]); exit(10); }

    read_write(fp_in, fp_out);  //copys first file into second file

    fclose(fp_in); fclose(fp_out);  //closes the opened files
    if( (fclose(fp_in) || fclose(fp_out)) )
        { printf("Files unable to be closed\n"); exit(10); }
    return 0;
}

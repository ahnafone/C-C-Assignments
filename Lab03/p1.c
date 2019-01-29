#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    int min = 0, max = 0, array_size, val, vals[200];
    int val_next, count = 0, negative = 1;
    char str[200];
    bool invalid = false;
    
    
    printf("Enter some integers: ");
    scanf ("%[^\n]%*c", str);
    
    //---------------------------------------------------------------------
    //Converts the C-string to an array of ints
    
    array_size = strlen(str);
    for (int i = 0; i < 200; i++) {
        vals[i] = 0;
    }
    
    for (int i = 0; i < array_size; i++) {
        val = str[i];
        if (val == 45)
            negative = -1;
        
        else if (val >= 48 && val <= 57) {
            val = val - 48;
            val_next = str[i+1];
            
            if (val_next >= 48 && val_next <= 57)
                vals[count] = vals[count] + (10*val*negative);
            else {
                vals[count] = vals[count] + (val*negative);
                count++;
                negative = 1;
            }
        }
        else if (val != 32) {
            invalid = true;
            break;
        }
    }
    //---------------------------------------------------------------------
    
    if (invalid) {
        printf("Invalid Input!\n");
        return 0;
    }
    else if (count == 0) {
        printf("Empty Input!\n");
        return 0;
    }
    
    min = max = vals[0];
    
    for (int i = 1; i < count; i++) {
        if (vals[i] > max)
            max = vals[i];
        else if (vals[i] < min)
            min = vals[i];
    }
    
    printf("%d %d\n", min, max);
    return (0);
}
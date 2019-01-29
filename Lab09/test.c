#include <stdio.h>

int main() {
    double sum = 0;
    for (int i = 0; i < 4000000; i++) {
        sum += i;
    }
    printf("Sum: %f\n", sum);
    return 0;
}

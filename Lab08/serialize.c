#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct X
{
    int a, b;
    char c, d;

    // prints object
    void print() const {
        printf("[ %d %d %d %d ] ", a, b, c, d);
    }

    // returns true iff object is equal to o
    bool equals(const X &o) const {
        return a == o.a && b == o.b && c == o.c && d == o.d;
    }
};

void serialize(const X &x, FILE *fp) {
    char str[32];
    int num = x->a;

    if (num >= 0)
        str[0] = '0';
    else if (num < 0) {
        str[0] = '1';
        num = -1 * num;
    }

    for (int i = 1; i < size; i++) {
        str[i] = (char) (48 + ( num % 2));
        num = num / 2;
    }

    fwrite(str, 1, sizeof(str), fp);

    num
}

//void deserialize(X &x, FILE *fp) {}

int main() {
    FILE *fp;
    X x = {1, 2, 3, 4};

    fp = fopen("serialize_test.txt", "w"));
    serialize(x, fp);  //copys first file into second file

    if(fclose(fp))
        { printf("File unable to be closed\n"); exit(10); }

    return 0;
}

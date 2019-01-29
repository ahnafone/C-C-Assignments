#include <cstdio>
#include <cstdlib>

int main()
{
    int N = 10000;
    FILE *fp = fopen("numbers.txt", "r");
    if (!fp) {
        perror("encountered fopen error"); exit(10);
    }
    for (int i=0; i < N; ++i) {
        int x;
        if (fscanf(fp, "%d", &x) != 1) {
            printf("encountered read error\n"); exit(10);
        }
        printf("%d\n", x);
    }
    if (fclose(fp)) {
        perror("encountered fclose error"); exit(10);
    }
    return 0;
}

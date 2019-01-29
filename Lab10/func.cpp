#include <iostream>

template <typename T>
T dot_product (T A[], T B[], int n) {
    // stop program if array size is less than 1
    if (n < 1) { printf("Error: invalid array size"); exit(1); }

    T sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + (A[i] * B[i]);
    return sum;
}

template <typename S>
void selection_sort (S A[], int n) {
    // stop program if array size is less than 1
    if (n < 1) { printf("Error: invalid array size"); exit(1); }

    S max;
    int max_index;
    while (true) {
        // set max to first element in array, and max_index to zero
        max = A[0];
        max_index = 0;

        //loop through elements to find the max value
        for (int i = 1; i < n; i++) {
            if (max < A[i]) {
                max = A[i];
                max_index = i;
            }
        }

        //switch the max with last element, then remove last element
        A[max_index] = A[n-1];
        A[n-1] = max;
        n = n - 1;

        if (n == 1)
            break;  //if one element left then exit loop
    }
}

int main()
{
    //-------------------------------------------------------------------------
    //                      Test Case 1: dot_product
    //-------------------------------------------------------------------------
    // Note: the arrays are all backwards so I can use them on Test Case 2
    int A[6] = {6, 5, 4, 3, 2, 1};
    int B[6] = {12, 11, 10, 9, 8, 7};
    printf("int: dot_product(A, B, 6) = %d\n", dot_product(A, B, 6));
    float C[6] = {6, 5, 4, 3, 2, 1};
    float D[6] = {12, 11, 10, 9, 8, 7};
    printf("float: dot_product(C, D, 6) = %f\n", dot_product(C, D, 6));
    double E[6] = {6, 5, 4, 3, 2, 1};
    double F[6] = {12, 11, 10, 9, 8, 7};
    printf("double: dot_product(E, F, 6) = %f\n\n", dot_product(E, F, 6));


    //-------------------------------------------------------------------------
    //                      Test Case 2: selection_sort
    //-------------------------------------------------------------------------
    selection_sort(A, 6);
    printf("int: selection_sort(A, 6) = { %d, %d, %d, %d, %d, %d }\n",
        A[0], A[1], A[2], A[3], A[4], A[5]);
    selection_sort(C, 6);
    printf("float: selection_sort(C, 6) = { %f, %f, %f, %f, %f, %f }\n",
        C[0], C[1], C[2], C[3], C[4], C[5]);
    selection_sort(E, 6);
    printf("double: selection_sort(E, 6) = { %f, %f, %f, %f, %f, %f }\n",
        E[0], E[1], E[2], E[3], E[4], E[5]);

    return 0;
}

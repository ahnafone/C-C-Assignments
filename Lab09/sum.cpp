#include <pthread.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>

// piece of work:
// add sub-array elements
// and store result
struct Job
{
    double* sub_array;
    int size;
    double sum;
};


// thread function: execute job
static void *sum_thread(void *data)
{
    Job *job = (Job*) data;
    job->sum = 0;
    for (int i = 0; i < job->size; i++)
        job->sum += job->sub_array[i];
    return nullptr;
}

// sum up n elements in array A
// using tn pthreads
// return sum
double sum(double A[], int n, int tn)
{
    assert(n > 0);
    assert(tn > 0);

    pthread_t threads[tn];
    Job jobs[tn];
    int startIndex = 0, endIndex = n / tn, tmp;
    double total = 0;

    for (int i = 0; i < tn; i++) {  // loops for every thread
        jobs[i].size = endIndex - startIndex;
        jobs[i].sub_array = (double*) malloc(jobs[i].size * sizeof(double));

        // enters values for subarray in jobs
        for (int j = startIndex; j < endIndex; j++)
            jobs[i].sub_array[j - startIndex] = A[j];

        tmp = startIndex;
        startIndex = endIndex;
        if(i == (tn-2))
            endIndex = n;
        else
            endIndex += tmp;
    }

    for (int i=0; i < tn; ++i) {
        Job &job = jobs[i];
        // ...
        pthread_create(&threads[i], nullptr, sum_thread, &job);
    }

    // wait for threads to complete
    // add up partial sums

    // ...
    for (int i=0; i < tn; ++i) {
        pthread_join(threads[i], nullptr);
        total += jobs[i].sum;
        free(jobs[i].sub_array);
    }

    // return result
    return total;
}


int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage: %s array-length threads\n", argv[0]);
        exit(1);
    }

    int length = 100'000;
    int tn = 1;

    length = atoi(argv[1]);
    tn = atoi(argv[2]);

    assert(length >= 1);
    assert(tn > 0);

    // create and initialize array
    double *A = new double[length];
    int count = 0;

    for (int i=0; i < length; ++i) {
        A[i] = count++;
    }

    // test
    double result;
    for (int i=0; i < 1'000; ++i) {
        result = sum(A, length, tn);
    }

    printf("done result = %f\n", result);
    delete [] A;
    return 0;
}

/*
Copy the test results here:

time ./a.out 4000000 1 :
done result = 7999998000000.000000

real    0m13.307s
user    0m8.625s
sys     0m0.141s

time ./a.out 4000000 2 :
done result = 7999998000000.000000

real    0m49.970s
user    0m12.750s
sys     0m34.828s

time ./a.out 4000000 3 :
done result = 7999998000000.000000

real    0m9.615s
user    0m9.406s
sys     0m0.297s

time ./a.out 4000000 4 :
done result = 7999998000000.000000

real    0m51.537s
user    0m13.797s
sys     0m33.297s


What could be the reason why running the program with 4
threads is less than 4 times faster than a single-threaded run?

Answer:
That is because the more threads you create and run, the more the resources
are used in syncronization, leaving less resources than before for carrying
the operations in each thread.


*/

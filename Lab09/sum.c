#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// piece of work:
// add sub-array elements
// and store result
struct Job
{
  // ...
};


// thread function: execute job
static void *sum_thread(void *data)
{
  // ...
  return 0;
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
  // ...

  for (int i=0; i < tn; ++i) {
    Job &job = jobs[i];
    // ...
    pthread_create(&threads[i], 0, sum_thread, &job);
  }

  // wait for threads to complete
  // add up partial sums

  // ...  
  for (int i=0; i < tn; ++i) {
    // ...
  }

  // return result
  // ...
}


int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("usage: %s array-length threads\n", argv[0]);
    exit(1);
  }

  int length = 100000;
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
  for (int i=0; i < 1000; ++i) {
    result = sum(A, length, tn);
  }
  
  printf("done result = %f\n", result);
  delete [] A;
}

/*
  Copy the test results here:

 



  What could be the reason why running the program with 4
  threads is less than 4 times faster than a single-threaded run?

  
  
*/

// this program tests s-sided dice that are based on a simple pseudo-random
// number generator

// The average result of rolls of dice with 2..10 sides is computed in
// individual threads

// fix the data race problem

#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <pthread.h>

// a simple pseudo-random number ganerator

// initialize with current time
unsigned int my_rng_seed = (unsigned int) time(0);

// initialize mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// compute next pseudo-random number (>=0 < 2^28)
unsigned int my_rng()
{
    my_rng_seed = 1664525 * my_rng_seed + 1013904223;
    // low order bits not very random => shift right
    // e.g. lowest bit toggles!
    return my_rng_seed >> 4;
}

// roll a die with s sides
// result in 1..s
// note: there are better implementations; this one
// generates biased samples. DON'T CHANGE!
int roll(int s)
{
    return my_rng() % s + 1;
}

// print roll statistic
void *roll_test(void *data)
{
    int sides = *(int*)data;

    const int N = 100'000;
    double sum = 0;

    pthread_mutex_lock(&mutex);     // lock mutex
    for (int i=0; i < N; ++i) {
        sum += roll(sides);
    }

    printf("sides=%d avg=%f (should be close to %f)\n",
    sides, sum/N, (1+sides)/2.0);
    pthread_mutex_unlock(&mutex);   // unlock mutex

    return nullptr;
}


int main()
{
    const int MIN_SIDES = 2;
    const int MAX_SIDES = 10;
    const int TN = MAX_SIDES - MIN_SIDES + 1;
    pthread_t threads[TN];
    int jobs[TN];

    // spawn a thread for testing each die with
    // MIN_SIDES .. MAX_SIDES sides
    for (int i=0; i < TN; ++i) {
        jobs[i] = MIN_SIDES + i;
        pthread_create(&threads[i], nullptr, roll_test, &jobs[i]);
    }

    // wait for test threads
    for (int i=0; i < TN; ++i) {
        pthread_join(threads[i], nullptr);
    }

    return 0;
}


/*

Change summary:

-Changes made to remove warnings during compilation:
    -changed line 17 to '.... = (unsigned int) test(0);'
    -added at 52: 'return nullptr;'

-Changes made while running with valgrind
    -added lock and unlock mutex lines at 48 and 55
    -added the line 'pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;' at 20


*/

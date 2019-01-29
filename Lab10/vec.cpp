#include <iostream>
#include <cassert>
#include <cstddef>
#include <cstdlib>

template <typename T>
//Code from Vector.h and Vector.cpp
//All 'int elem' or similar were converted to 'T elem' or similar
class Vector
{
public:
    // user accessible member functions
    // constructor: allocate n elements
    // called when vector is created
    Vector(int N)
    {
        assert(N > 0);
        elems = new T[static_cast<size_t>(N)]; // make -Wconversion happy
        n = N;
    }

    // destructor: called when vector
    // is going out of scope or is destroyed
    ~Vector()
    {
        delete [] elems;
    }

    // returns number of elements
    int size() const
    {
        return n;
    }

    // returns i-th element
    T get(int i) const
    {
        assert(i >= 0 && i < n);
        return elems[i];
    }

    // sets i-th element to v
    void set(int i, T v)
    {
        assert(i >= 0 && i < n);
        elems[i] = v;
    }

    // after bounds checking in debug mode
    // returns reference to i-th Vector element
    T operator[](int i) {
        return get(i);
    }

private:
    // data members hidden from users
    T *elems;
    int n;
};


int main()
{
    //Test Vector<int>
    const int N = 5;
    Vector<int> vi(N);
    //set each value of vi
    for (int i = 0; i < 5; i++)
        vi.set(i, i+1);
    printf("vi = { %d, %d, %d, %d, %d }\n",
        vi[0], vi.get(1), vi[2], vi.get(3), vi[4]);
    printf("size of vi: %d\n", vi.size());

    //Test Vector<const char *>
    Vector<const char *> vs(N);
    //set each value of vs
    for (int i = 0; i < 5; i++)
        vs.set(i, "foo");
    printf("vs = { '%s', '%s', '%s', '%s', '%s' }\n",
        vs[0], vs.get(1), vs[2], vs.get(3), vs[4]);
    printf("size of vs: %d\n", vs.size());
    
    return 0;
}

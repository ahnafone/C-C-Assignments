#pragma once

#include <cstdio>

// square double floating point matrix
// (flat array representation)
// DO NOT CHANGE!

class Matrix
{
public:
  // constructor, creates n by n matrix
  // and sets all elements to 0
  // pre-condition: n > 0
  Matrix(int n);

  // destructor, frees all memory
  ~Matrix();

  // sets all elements to v
  void set(double v);
  
  // checks indexes in debug mode and
  // returns reference to element (i,j)
  double &e(int i, int j);

  // returns dimension
  int dimension();

  // creates a copy of this matrix
  // on the heap and returns a pointer to it.
  // The entries pointers of the returned matrix and
  // the original matrix must be different
  Matrix *clone();
  
  // prints all elements to standard output
  // format: (+xx.xx)
  void print()
  {
    for (int i=0; i < dim; ++i) {
      for (int j=0; j < dim; ++j) {
        printf("%+6.2f ", e(i, j));
      }
      printf("\n"); // row ends
    }
  }
  
private:
  // matrix dimension
  int dim;
  // array of entries (sole owner)
  double *entries;
};

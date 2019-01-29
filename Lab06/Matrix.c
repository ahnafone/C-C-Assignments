#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

// constructor, creates n by n matrix
// and sets all elements to 0
// pre-condition: n > 0
Matrix::Matrix(int n) {
  if (n <= 0) {  //exit if n <= 0
    printf("N has to be greater than 0. Exiting...\n");
    exit(1);
  }
  dim = n;  // n is the dimension of the matrix
  entries = new double[n*n];  //allocates n*n amount of memory in heap
  set(0);  //set all the values to 0
}

// destructor, frees all memory
Matrix::~Matrix() {
  delete [] entries;
  entries = NULL;
}

// sets all elements to v
void Matrix::set(double v) {
  int tmp = dim*dim;
  for (int i = 0; i < (tmp); i++)
    entries[i] = v;
}

// checks indexes in debug mode and
// returns reference to element (i, j)
double &Matrix::e(int i, int j) {
  return entries[ (i*dim + j) ];
}

// returns dimension
int Matrix::dimension() {
  return dim;
}

// creates a copy of this matrix
// on the heap and returns a pointer to it.
// The entries pointers of the returned matrix and
// the original matrix must be different
Matrix *Matrix::clone() {
  Matrix *new_matrix = new Matrix(dim);
  new_matrix->set(entries[0]);
  return new_matrix;
}

#include "Matrix.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>

int main()
{

  // test code for all functions
  // including failing pre-conditions
  // (guarded by #if 0 ... #endif)
  
  Matrix *matrix = new Matrix(10);
  matrix->set(5);
  
  printf("Testing set(5): \n");
  printf("Dimension: %d\n", matrix->dimension());
  matrix->print();
  
  matrix->set(10);
  printf("Testing set(10): \n");
  printf("Dimension: %d\n", matrix->dimension());
  matrix->print();
  
  Matrix *new_matrix = matrix->clone();
  printf("Testing clone(): \n");
  printf("Dimension of clone: %d\n", new_matrix->dimension());
  new_matrix->print();

  matrix->set(1);
  new_matrix->set(2);
  printf("Testing matrix->set(1) and new_matrix->set(2): \n");
  printf("Dimension of matrix: %d\n", matrix->dimension());
  matrix->print();
  printf("Dimension of clone: %d\n", new_matrix->dimension());
  new_matrix->print();

  free(matrix);
  free(new_matrix);
  return 0;
}

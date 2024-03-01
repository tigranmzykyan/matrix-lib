

#include "../s21_matrix.h"



int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (!result) return INCORRECT_MATRIX;
  if (rows <= 0 || columns <= 0 || (rows * columns == 1)) return CALC_ERR;
  double** matrix = calloc(rows, sizeof(double*));
  if (!matrix) return INCORRECT_MATRIX;
  for (int i = 0; i < rows; i++) {
    matrix[i] = calloc(columns, sizeof(double));
    if (!matrix[i]) return INCORRECT_MATRIX;
  }
  result->matrix = matrix;
  result->columns = columns;
  result->rows = rows;
  return OK;
}

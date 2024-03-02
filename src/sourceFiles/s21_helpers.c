#include "../s21_matrix.h"

int is_correct(matrix_t *A) {
  return A->matrix != NULL || A->rows > 0 || A->columns > 0;
}

int is_eq_size(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

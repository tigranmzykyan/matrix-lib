#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (is_correct(A)) {
    if (A->rows == A->columns && A->rows != 1) {
      int n = A->rows;
      matrix_t tmp = {0};
      int codec1 = 0, codec2 = 0;
      codec1 = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
      if (codec1 == OK) codec2 = s21_create_matrix(n, n, result);
      if (codec1 == OK && codec2 == OK) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            double determinant = 0;
            get_cofactor(A, &tmp, i, j, n);
            s21_determinant(&tmp, &determinant);
            result->matrix[i][j] = determinant * pow(-1, i + j);
          }
        }
        s21_remove_matrix(&tmp);
      }
    } else {
      res = CALC_ERROR;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

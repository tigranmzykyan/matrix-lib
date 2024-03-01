#include "../s21_matrix.h"

int is_correct(matrix_t *A) {
    return A->matrix != NULL || A->rows > 0 || A->columns > 0;
}

int is_eq_size(matrix_t *A, matrix_t *B) {
    return A->rows == B->rows && A->columns == B->columns;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    if (is_correct(A) && is_correct(B)) {
        if (is_eq_size(A, B)) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) return FAILURE;
                }
            }
        } else {
            return FAILURE;
        }
    } else {
        return FAILURE;
    }
    return SUCCESS;
}


//int s21_eq_matrix(matrix_t *A, matrix_t *B) {
//  if (!A || !B) return 0;
//  if (!is_eq_mat_size(A, B)) return 0;
//  int x = A->columns, y = A->rows;
//  int res = SUCCESS;
//  for (int i = 0; i < y; i++)
//    for (int j = 0; j < x; j++)
//      if (!is_eq_d(A->matrix[i][j], B->matrix[i][j], 1E-7)) res = FAILURE;
//  return res;
//}

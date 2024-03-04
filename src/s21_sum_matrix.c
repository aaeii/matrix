#include "s21_matrix.h"
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = INCORRECT;
  if (check_incorrectness(A) && check_incorrectness(B)) {
    res = ERROR;
    if (A->columns == B->columns && A->rows == B->rows &&
        s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          res = OK;
        }
      }
    }
  }
  return res;
}
#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if (check_incorrectness(A) && check_incorrectness(B) && A->rows == B->rows &&
      A->columns == B->columns) {
    result = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}
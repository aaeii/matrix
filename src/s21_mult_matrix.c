#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (check_incorrectness(A) == 0 || check_incorrectness(B) == 0) {
    res = INCORRECT;
  } else if (A->columns == B->rows) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int l = 0; l < B->rows; l++) {
          result->matrix[i][j] += A->matrix[i][l] * B->matrix[l][j];
        }
      }
    }
  } else {
    res = ERROR;
  }

  return res;
}
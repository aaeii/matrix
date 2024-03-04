#include "s21_matrix.h"
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = INCORRECT;
  if (check_incorrectness(A)) {
    if (A->columns == A->rows) {
      error = OK;
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double det = 0;
          matrix_t n;
          Minor(i, j, A, &n);
          s21_determinant(&n, &det);
          result->matrix[i][j] = det * pow(-1, i + j);
          s21_remove_matrix(&n);
        }
      }
    } else {
      error = ERROR;
    }
  }
  return error;
}
#include "s21_matrix.h"
int check_incorrectness(matrix_t *A) {
  return A != NULL && A->rows > 0 && A->columns > 0 && A->matrix != NULL;
}
double det_square_matrix(matrix_t A) {
  return A.matrix[0][0] * A.matrix[1][1] - A.matrix[1][0] * A.matrix[0][1];
}
int Minor(int row, int column, matrix_t *A, matrix_t *result) {
  int error = 1;
  if (A->matrix != NULL) {
    error = s21_create_matrix(A->rows - 1, A->columns - 1, result);
    if (error == 0) {
      int new_row = 0, new_column = 0;
      for (int i = 0; i < A->rows; i++) {
        new_row = i;
        if (i > row - 1) {
          new_row--;
        }
        for (int j = 0; j < A->columns; j++) {
          new_column = j;
          if (j > column - 1) {
            new_column--;
          }
          if (i != row && j != column) {
            result->matrix[new_row][new_column] = A->matrix[i][j];
          }
        }
      }
    }
  }
  return error;
}

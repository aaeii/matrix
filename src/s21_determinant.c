#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = 1, sign_one = 1;
  double r = 0, det = 0;
  if (check_incorrectness(A)) {
    err = 2;
    if (A->rows == A->columns) {
      err = 0;
      if (A->rows == 1) {
        r = A->matrix[0][0];
      } else if (A->rows == 2) {
        r = det_square_matrix(*A);
      } else {
        matrix_t minor_matr;
        for (int i = 0; i < A->columns; i++) {
          Minor(0, i, A, &minor_matr);
          s21_determinant(&minor_matr, &det);
          r += sign_one * A->matrix[0][i] * det;
          sign_one *= -1;
          s21_remove_matrix(&minor_matr);
        }
      }
    }
  }
  *result = r;
  return err;
}

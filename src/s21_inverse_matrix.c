#include "s21_matrix.h"
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (check_incorrectness(A)) {
    double det = 0;
    s21_determinant(A, &det);
    if (fabs(det) > 1e-6) {
      matrix_t calc_matr, transp_matr;
      s21_calc_complements(A, &calc_matr);
      s21_transpose(&calc_matr, &transp_matr);
      s21_mult_number(&transp_matr, 1 / det, result);
      s21_remove_matrix(&calc_matr);
      s21_remove_matrix(&transp_matr);

    } else {
      error = ERROR;
    }
  } else {
    error = INCORRECT;
  }
  return error;
}

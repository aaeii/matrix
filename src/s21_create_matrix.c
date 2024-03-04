#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    error = INCORRECT;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      error = ERROR;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    }
  }
  if (error == 0) {
    result->rows = rows;
    result->columns = columns;
  }
  return error;
}

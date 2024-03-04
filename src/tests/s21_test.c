#include "s21_test.h"

START_TEST(test_s21_create_matrix) {
  matrix_t A;
  int ret = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&A);

  ret = s21_create_matrix(0, 2, &A);
  ck_assert_int_eq(ret, 1);

  ret = s21_create_matrix(-2, 0, &A);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(test_s21_eq_matrix) {
  matrix_t A, B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, 0);

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[1][1] = 100;
  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix) {
  matrix_t A, B, res_my, res_org;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &res_org);
  int ret = s21_sum_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 1, &A);
  s21_create_matrix(4, 4, &B);
  ret = s21_sum_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;

  res_org.matrix[0][0] = 2;
  res_org.matrix[0][1] = 2;
  res_org.matrix[0][2] = 3;
  res_org.matrix[1][0] = 2;
  res_org.matrix[1][1] = 4;
  res_org.matrix[1][2] = 5;
  res_org.matrix[2][0] = 3;
  res_org.matrix[2][1] = 4;
  res_org.matrix[2][2] = 7;
  ret = s21_sum_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST
START_TEST(test_s21_sub_matrix) {
  matrix_t A, B, res_my, res_org;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &res_org);
  int ret = s21_sub_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 5, &A);
  s21_create_matrix(4, 4, &B);
  ret = s21_sub_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(4, 4, &B);
  ret = s21_sub_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 3, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;

  res_org.matrix[0][0] = 0;
  res_org.matrix[0][1] = 2;
  res_org.matrix[0][2] = 3;
  res_org.matrix[1][0] = -2;
  res_org.matrix[1][1] = 4;
  res_org.matrix[1][2] = 5;
  ret = s21_sub_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 3, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = i;
      B.matrix[i][j] = i;
    }
  }
  ret = s21_sub_matrix(&A, &B, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_mult_number) {
  matrix_t A, res_my, res_org;
  int ret = 0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_org);
  ret = s21_mult_number(&A, 5, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_org);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i + j;
      res_org.matrix[i][j] = (i + j) * (10);
    }
  }
  ret = s21_mult_number(&A, 10, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_mult_matrix) {
  matrix_t A, B, res_mat, res_org;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 10;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;

  res_org.matrix[0][0] = 5;
  res_org.matrix[0][1] = 0;
  res_org.matrix[1][0] = 18;
  res_org.matrix[1][1] = 0;
  int ret = s21_mult_matrix(&A, &B, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 4, &A);
  s21_create_matrix(2, 2, &B);
  ret = s21_mult_matrix(&A, &B, &res_mat);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 1, &B);
  s21_create_matrix(2, 1, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 10;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 1;
  B.matrix[1][0] = 1;

  res_org.matrix[0][0] = 3;
  res_org.matrix[1][0] = 14;
  ret = s21_mult_matrix(&A, &B, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(-2, -2, &A);
  s21_create_matrix(-2, -1, &B);
  ret = s21_mult_matrix(&A, &B, &res_mat);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_transpose) {
  matrix_t A, res_mat, res_org;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  res_org.matrix[0][0] = 1;
  res_org.matrix[0][1] = 3;
  res_org.matrix[1][0] = 2;
  res_org.matrix[1][1] = 4;
  int ret = s21_transpose(&A, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 0, &A);
  ret = s21_transpose(&A, &res_mat);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant) {
  matrix_t matrix;
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 9;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[0][3] = 4;

  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[1][3] = 4;

  matrix.matrix[2][0] = 4;
  matrix.matrix[2][1] = 4;
  matrix.matrix[2][2] = 9;
  matrix.matrix[2][3] = 9;

  matrix.matrix[3][0] = 1;
  matrix.matrix[3][1] = 1;
  matrix.matrix[3][2] = 5;
  matrix.matrix[3][3] = 1;
  double det = 0;
  int ret = s21_determinant(&matrix, &det);
  ck_assert_uint_eq(det, -578);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix);

  s21_create_matrix(1, 1, &matrix);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = 10;
    }
  }
  ret = s21_determinant(&matrix, &det);
  ck_assert_uint_eq(det, 10);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix);
  s21_create_matrix(2, 2, &matrix);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = 2;
    }
  }
  ret = s21_determinant(&matrix, &det);
  ck_assert_uint_eq(det, 0);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_calc_complements) {
  matrix_t A, res_org, res_my;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  res_org.matrix[0][0] = 0;
  res_org.matrix[0][1] = 10;
  res_org.matrix[0][2] = -20;
  res_org.matrix[1][0] = 4;
  res_org.matrix[1][1] = -14;
  res_org.matrix[1][2] = 8;
  res_org.matrix[2][0] = -8;
  res_org.matrix[2][1] = -2;
  res_org.matrix[2][2] = 4;
  int ret = s21_calc_complements(&A, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(3, 5, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i + 1;
    }
  }
  ret = s21_calc_complements(&A, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&A);

  s21_create_matrix(-1, -1, &A);
  ret = s21_calc_complements(&A, &res_my);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(test_s21_inverse_matrix) {
  matrix_t A, res_org, res_my;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_org);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  res_org.matrix[0][0] = 1;
  res_org.matrix[0][1] = -1;
  res_org.matrix[0][2] = 1;
  res_org.matrix[1][0] = -38;
  res_org.matrix[1][1] = 41;
  res_org.matrix[1][2] = -34;
  res_org.matrix[2][0] = 27;
  res_org.matrix[2][1] = -29;
  res_org.matrix[2][2] = 24;
  int ret = s21_inverse_matrix(&A, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
  matrix_t c, d;
  s21_create_matrix(3, 3, &c);
  s21_create_matrix(3, 3, &d);

  ret = s21_inverse_matrix(&c, &d);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&c);
  s21_remove_matrix(&d);

  s21_create_matrix(-2, -2, &A);
  ret = s21_inverse_matrix(&A, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite* check(void) {
  Suite* s;
  TCase* tc_1;
  s = suite_create("matrix_test");

  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, test_s21_create_matrix);
  tcase_add_test(tc_1, test_s21_eq_matrix);
  tcase_add_test(tc_1, test_s21_sum_matrix);
  tcase_add_test(tc_1, test_s21_sub_matrix);
  tcase_add_test(tc_1, test_s21_mult_number);
  tcase_add_test(tc_1, test_s21_mult_matrix);
  tcase_add_test(tc_1, test_s21_transpose);
  tcase_add_test(tc_1, test_s21_determinant);
  tcase_add_test(tc_1, test_s21_calc_complements);
  tcase_add_test(tc_1, test_s21_inverse_matrix);
  suite_add_tcase(s, tc_1);

  return s;
}

void run_test(Suite* s, int* fail) {
  SRunner* runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main(void) {
  int fail = 0;
  run_test(check(), &fail);

  return fail;
}

#ifndef TEST_H
#define TEST_H

#include <check.h>

#include "../s21_matrix.h"
Suite *check(void);
void run_test(Suite *s, int *fail);
#endif  // TEST_H
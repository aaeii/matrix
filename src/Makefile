CC = gcc
CFLAGS= -Wall -Werror -Wextra -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lcheck -lm -lrt -lpthread -lsubunit
else
    det_OS = -lcheck -lm -lpthread
endif

all: clean s21_matrix.a test gcov_report

s21_matrix.a: s21_matrix.o
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

s21_matrix.o: s21_*.c s21_matrix.h
	$(CC) $(CFLAGS) s21_*.c -c

test: clean
	$(CC) $(CFLAGS) --coverage s21_*.c tests/s21_*.c -o testresult $(det_OS)
	./testresult

gcov_report: test
	lcov -t "s21_matrix_test" -o matrix.info -c -d .
	genhtml -o report matrix.info
	open report/index.html
	rm -rf *.gcno *gcda *.gcov

clang:
	clang-format -style=Google -n *.c *.h tests/*.c tests/*.h

style:
	clang-format -style=Google -i *.c *.h tests/*.c tests/*.h

clean:
	rm -rf testresult *.gcda *.gcno *.o *.info *.a tests/*.gcno tests/report report test.dSYM
valgrind:
	valgrind --tool=memcheck --leak-check=yes --log-file=log.txt ./testresult


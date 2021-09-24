#include "functions.h"
#include "test.h"

int main() {
	print_error(test_sq_eq());

	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

	printf("Введите через пробел коэффициенты a, b и c: ");
	int num = scanf("%lg %lg %lg", &a, &b, &c);

	SQ_EQ_ERRORS result = (num != 3)? sq_eq_too_few_args : sq_eq_ok;
	while (result != sq_eq_ok) {
		print_error(result);
		printf("Try again:\n");
		while (getchar() != '\n') {}
		num = scanf("%lg %lg %lg", &a, &b, &c);
		result = (num != 3)? sq_eq_too_few_args : sq_eq_ok;
	}

	SQ_EQ_ROOTS numberOfRoots;
	print_error(solve_square(a, b, c, &x1, &x2, &numberOfRoots));

	print_error(print_answer(numberOfRoots, x1, x2));

	return 0;
}
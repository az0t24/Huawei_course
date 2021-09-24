#include "functions.h"

SQ_EQ_ERRORS solve_square(const double a, const double b, const double c,
	                      double* x1, double* x2, SQ_EQ_ROOTS* num) {
	if (x1 == x2) {
		return sq_eq_equal_pointers;
	}
	if (x1 == NULL || x2 == NULL) {
		return sq_eq_NULL_pointer;
	}

	if (is_equal_to_zero(a)) {
		return solve_linear(b, c, x1, num);
	} else {
		double d = b * b - 4 * a * c;

		if (is_equal_to_zero(d)) {
			*x1 = (-b + sqrt(d)) / (2 * a);
			*num = sq_eq_one_root;
		} else if (is_below_zero(d)) {
			*num = sq_eq_no_root;
		} else {
			*x1 = (-b + sqrt(d)) / (2 * a);
			*x2 = (-b - sqrt(d)) / (2 * a);

			*num = sq_eq_two_roots;
		}
	}
	return sq_eq_ok;
}

SQ_EQ_ERRORS solve_linear(const double b, const double c, double* x1, SQ_EQ_ROOTS* num) {
	if (is_equal_to_zero(b)) {
		if (is_equal_to_zero(c)) {
			*num = sq_eq_inf_roots;
		} else {
			*num = sq_eq_no_root;
		}
	} else {
		*x1 = -c / b;
		*num = sq_eq_one_root;
	}
	return sq_eq_ok;
}

bool is_equal_to_zero(const double value) {
	return fabs(value) < EPS;
}

bool is_above_zero(const double value) {
	return !(is_equal_to_zero(value)) && value > 0;
}

bool is_below_zero(const double value) {
	return !(is_equal_to_zero(value)) && value < 0;
}

SQ_EQ_ERRORS print_answer(const SQ_EQ_ROOTS num, const double x1, const double x2) {
	switch (num) {

		case sq_eq_no_root: printf("Нет корней\n");
				break;

		case sq_eq_one_root: printf("Один корень: x = %lf\n", x1);
				break;

		case sq_eq_two_roots: printf("Два корня: x1 = %lf и x2 = %lf\n", x1, x2);
				break;

		case sq_eq_inf_roots: printf("Бесконечное число корней\n");
				break;

		default: return sq_eq_print_answer_problem;
	}
	return sq_eq_ok;
}

void print_error(const SQ_EQ_ERRORS code) {
	if (code == sq_eq_ok) {
		return;
	}
	char* error_codes[] = {"",
						   "Too few arguments",
						   "Equal pointers",
						   "NULL pointer",
						   "Print_answer problems",
						   "Tests was not passed"};
	printf("Error: %s\n", error_codes[code]);
}
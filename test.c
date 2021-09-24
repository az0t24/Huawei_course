#include "test.h"

SQ_EQ_ERRORS test_sq_eq() {
	double x1 = 0, x2 = 0;
	SQ_EQ_ROOTS num = 0;
	SQ_EQ_ERRORS answer = sq_eq_ok;
	SQ_EQ_ERRORS code = sq_eq_ok;

	code = solve_square(1, 0, 0, &x1, &x2, &num);
	answer = attempt(x1, x2, num, code, 0, 0, sq_eq_one_root);
	if (answer == sq_eq_tests_not_passed) {
		return answer;
	}

	code = solve_square(0, 1, 0, &x1, &x2, &num);
	answer = attempt(x1, x2, num, code, 0, 0, sq_eq_one_root);
	if (answer == sq_eq_tests_not_passed) {
		return answer;
	}

	code = solve_square(0, 0, 1, &x1, &x2, &num);
	answer = attempt(x1, x2, num, code, 0, 0, sq_eq_no_root);
	if (answer == sq_eq_tests_not_passed) {
		return answer;
	}
	
	code = solve_square(1, 3, 2, &x1, &x2, &num);
	answer = attempt(x1, x2, num, code, -1, -2, sq_eq_two_roots);
	if (answer == sq_eq_tests_not_passed) {
		return answer;
	}
	
	code = solve_square(0, 0, 0, &x1, &x2, &num);
	answer = attempt(x1, x2, num, code, 0, 0, sq_eq_inf_roots);
	if (answer == sq_eq_tests_not_passed) {
		return answer;
	}
}



SQ_EQ_ERRORS attempt(double x1, double x2, SQ_EQ_ROOTS num, SQ_EQ_ERRORS err,
					 double res1, double res2, SQ_EQ_ROOTS res3) {
	if (err != sq_eq_ok) {
		return sq_eq_tests_not_passed;
	}

	if (num != res3) {
		return sq_eq_tests_not_passed;
	}

	if (num == sq_eq_inf_roots || num == sq_eq_no_root) {
		return sq_eq_ok;
	}

	if (x1 != res1) {
		return sq_eq_tests_not_passed;
	}

	if (num == sq_eq_one_root) {
		return sq_eq_ok;
	}

	if (x2 != res2) {
		return sq_eq_tests_not_passed;
	}

	return sq_eq_ok;
}
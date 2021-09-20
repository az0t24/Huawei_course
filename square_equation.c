#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF_ROOTS -1
#define EPS 10e-9

/**
 * Function finds the roots of square equation.
 * @param [in] a a coefficient before x^2
 * @param [in] b a coefficient before x
 * @param [in] c a free member
 * @param [out] x1 a pointer to the first root
 * @param [out] x2 a pointer to the second root
 * \return Number of roots of square equation.
 */
int solve_square(const double a, const double b, const double c, double* x1, double* x2);

/**
 * Function prints the number of roots.
 * @param [in] num a number of roots
 * @param [in] x1 first root (if it exists)
 * @param [in] x2 second root (if it exists)
 */ 
void print_answer(const int num, const double x1, const double x2);

int main() {
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

	printf("Введите через пробел коэффициенты a, b и c: ");
	scanf("%lg %lg %lg", &a, &b, &c);

	int numberOfRoots = solve_square(a, b, c, &x1, &x2);

	print_answer(numberOfRoots, x1, x2);

	return 0;
}

int solve_square(const double a, const double b, const double c, double* x1, double* x2) {
	
	assert(x1 != x2);
	assert(x1 != NULL);
	assert(x2 != NULL);

	if (fabs(a) < EPS) {
		if (fabs(b) < EPS) {
			if (fabs(c) < EPS) {
				return INF_ROOTS;
			} else {
				return 0;
			}
		} else {
			*x1 = -c / b;
			
			return 1;
		}
	} else {
		double d = b * b - 4 * a * c;

		if (fabs(d) < EPS) {
			*x1 = (-b + sqrt(d)) / (2 * a);

			return 1;
		} else if (d < 0) {
			return 0;
		} else {
			*x1 = (-b + sqrt(d)) / (2 * a);
			*x2 = (-b - sqrt(d)) / (2 * a);

			return 2;
		}
	}
}

void print_answer(const int num, const double x1, const double x2) {
	switch (num) {

		case 0: printf("Нет корней\n");
				break;

		case 1: printf("Один корень: x = %lf\n", x1);
				break;

		case 2: printf("Два корня: x1 = %lf и x2 = %lf\n", x1, x2);
				break;

		case INF_ROOTS: printf("Бесконечное число корней\n");
				break;

		default: printf("Произошла ошибка\n");
	}
}

void test() {
	double x1 = -1, x2 = -1;
	int num;

	num = solve_square(1, 0, 0, &x1, &x2);
	assert(num == 1);
	assert(x1 == 0);
	assert(x2 == -1);

	num = solve_square(0, 1, 0, &x1, &x2);
	assert(num == 1);
	assert(x1 == 0);
	assert(x2 == -1);

	num = solve_square(0, 0, 1, &x1, &x2);
	assert(num == 0);
	assert(x1 == 0);
	assert(x2 == -1);

	num = solve_square(1, 3, 2, &x1, &x2);
	assert(num == 2);
	assert(x1 == -1);
	assert(x2 == -2);

	num = solve_square(0, 0, 0, &x1, &x2);
	assert(num = INF_ROOTS);
}
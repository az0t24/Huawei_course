#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define EPS 10e-9

enum SQ_EQ_ERRORS {
    sq_eq_ok,
    sq_eq_too_few_args,
    sq_eq_equal_pointers,
    sq_eq_NULL_pointer,
    sq_eq_print_answer_problem,
    sq_eq_tests_not_passed,
};
typedef enum SQ_EQ_ERRORS SQ_EQ_ERRORS;

enum SQ_EQ_ROOTS {
    sq_eq_no_root,
    sq_eq_one_root,
    sq_eq_two_roots,
    sq_eq_inf_roots,
};
typedef enum SQ_EQ_ROOTS SQ_EQ_ROOTS;

/**
 * Function finds the roots of square equation.
 * @param [in] a a coefficient before x^2
 * @param [in] b a coefficient before x
 * @param [in] c a free member
 * @param [out] x1 a pointer to the first root
 * @param [out] x2 a pointer to the second root
 * @param [out] num a pointer to the number of roots
 * \return Number of roots of square equation.
 */
SQ_EQ_ERRORS solve_square(const double a, const double b, const double c, double* x1, double* x2, SQ_EQ_ROOTS* num);

/**
 * Function prints the number of roots.
 * @param [in] num a number of roots
 * @param [in] x1 first root (if it exists)
 * @param [in] x2 second root (if it exists)
 */ 
SQ_EQ_ERRORS print_answer(const SQ_EQ_ROOTS num, const double x1, const double x2);

/**
 * Function finds the roots of linear equation.
 * @param [in] b a coefficient before x
 * @param [in] c a free member
 * @param [out] x1 a pointer to the first root
 * @param [out] num a pointer to the number of roots
 * \return Error code: ok, if success.
 */
SQ_EQ_ERRORS solve_linear(const double b, const double c, double* x1, SQ_EQ_ROOTS* num);

/**
 * Function check is number equal to zero or not
 * @param [in] value a number to compare
 * \return True, if value is zero, and false else.
 */
bool is_equal_to_zero(const double value);

/**
 * Function check is number greater than zero or not
 * @param [in] value a number to compare
 * \return True, if value is greater than zero, and false else.
 */
bool is_above_zero(const double value);

/**
 * Function check is number less than zero or not
 * @param [in] value a number to compare
 * \return True, if value is less than zero, and false else.
 */
bool is_below_zero(const double value);

/**
 * Function prints the name of the error.
 * @param [in] code a code of error
 */
void print_error(const SQ_EQ_ERRORS code);
#include <stdio.h>
#include <stdbool.h>

// defining the Rational struct
struct rational
{
    int numerator;
    int denominator;
};
typedef struct rational Rational;

/***************************************************
 * Rational create_rational(const int num, const int denom);
 * creates a Rational variable in it's simpliest form
 *
 * Parameters:
 *   const int num: numerator integer
 *   const int denom: denominator integer
 * Returns:
 *   a Rational
 ************************************************/
Rational create_rational(const int num, const int denom);

/***************************************************
 * Rational copy_rational(const Rational* orig);
 * Creates a deep copy of the passed in Rational variable
 *
 * Parameters:
 *   const Rational* orig: pointer to a Rational variable
 * Returns:
 *   the Rational deep copy
 ************************************************/
Rational copy_rational(const Rational *orig);

/***************************************************
 * void simplify(Rational*);
 * simplifies the numerator & denominator of the referenced Rational variable
 *
 * Parameters:
 *   a pointer to a rational variable
 * Returns:
 *   nothing
 ************************************************/
void simplify(Rational *);

/***************************************************
 * int gcd(int a, int b);
 * finds the greatest common divisor
 *
 * Parameters:
 *   int a: numerator
 *   int b: denominator
 * Returns:
 *   the greatest common divisor
 ************************************************/
int gcd(int a, int b);

/***************************************************
 * Rational add(const Rational* num1, const Rational* num2);
 * Creates a new Rational that contains the sum of the two input values
 *
 * Parameters:
 *   const Rational* num1: pointer to the first Rational variable
 *   const Rational* num2: pointer to the second Rational variable
 * Returns:
 *   a new Rational in the simpliest form
 ************************************************/
Rational add(const Rational *num1, const Rational *num2);

/***************************************************
 * Rational subtract(const Rational* num1, const Rational* num2);
 * Creates a new Rational that contains the difference of the two input values.
 *
 * Parameters:
 *   const Rational* num1: pointer to the first Rational variable
 *   const Rational* num2: pointer to the second Rational variable
 * Returns:
 *   a new Rational in the simpliest form
 ************************************************/
Rational subtract(const Rational *num1, const Rational *num2);

/***************************************************
 * Rational multiply(const Rational* num1, const Rational* num2);
 * Creates a new Rational that contains the product of the two input values
 *
 * Parameters:
 *   const Rational* num1: pointer to the first Rational variable
 *   const Rational* num2: pointer to the second Rational variable
 * Returns:
 *   a new Rational in the simpliest form
 ************************************************/
Rational multiply(const Rational *num1, const Rational *num2);

/***************************************************
 * Rational divide(const Rational* num1, const Rational* num2);
 * Creates a new Rational that contains the division of the two input values
 *
 * Parameters:
 *   const Rational* num1: pointer to the first Rational variable
 *   const Rational* num2: pointer to the second Rational variable
 * Returns:
 *   a new Rational in the simpliest form
 ************************************************/
Rational divide(const Rational *num1, const Rational *num2);

/***************************************************
 * void print(FILE* file, const Rational* rational);
 * Prints a rational number to the specified file pointer without putting a newline character
 *
 * Parameters:
 *   FILE* file: a pointer to a file
 *   const Rational* num1: pointer to a Rational variable
 * Returns:
 *   nothing
 ************************************************/
void print(FILE *file, const Rational *rational);

/***************************************************
 * bool equal(const Rational* num1, const Rational* num2);
 * checks if the two rational variables are equal
 *
 * Parameters:
 *   const Rational* num1: pointer to the first Rational variable
 *   const Rational* num2: pointer to the second Rational variable
 * Returns:
 *   Returns true if the two Rationals are equal, false otherwise
 ************************************************/
bool equal(const Rational *num1, const Rational *num2);

/***************************************************
 * int compare(const Rational* num1, const Rational* num2);
 * compares two rational number
 *
 * Parameters:
 *   const Rational* num1: pointer to the first Rational variable
 *   const Rational* num2: pointer to the second Rational variable
 * Returns:
 *   Returns 0 if the two Rationals are equal, -1 if num1 is less than num2, and 1 if num1 is greater than num2
 ************************************************/
int compare(const Rational *num1, const Rational *num2);
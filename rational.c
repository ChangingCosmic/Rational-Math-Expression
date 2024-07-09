#include "rational.h"

Rational create_rational(const int num, const int denom)
{
    Rational rat = {num, denom};
    simplify(&rat);
    return rat;
}

Rational copy_rational(const Rational *orig)
{
    Rational copy = {orig->numerator, orig->denominator};
    simplify(&copy);
    return copy;
}

void simplify(Rational *rat)
{
    if (0 == rat->denominator)
    {
        printf("Denominator is zero, cannot simplify.");
    }

    int divisor = gcd(rat->numerator, rat->denominator);

    rat->numerator = rat->numerator / divisor;
    rat->denominator = rat->denominator / divisor;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

Rational add(const Rational *num1, const Rational *num2)
{
    Rational result;

    result.numerator = (num1->numerator * num2->denominator) + (num2->numerator * num1->denominator);
    result.denominator = num1->denominator * num2->denominator;

    simplify(&result);
    return result;
}

Rational subtract(const Rational *num1, const Rational *num2)
{
    Rational result;

    result.numerator = (num1->numerator * num2->denominator) - (num2->numerator * num1->denominator);
    result.denominator = num1->denominator * num2->denominator;

    simplify(&result);
    return result;
}

Rational multiply(const Rational *num1, const Rational *num2)
{
    Rational result;

    result.numerator = num1->numerator * num2->numerator;
    result.denominator = num1->denominator * num2->denominator;

    simplify(&result);
    return result;
}

Rational divide(const Rational *num1, const Rational *num2)
{
    Rational result;
    result.numerator = num1->numerator * num2->denominator;
    result.denominator = num1->denominator * num2->numerator;
    simplify(&result);
    return result;
}

void print(FILE *file, const Rational *rational)
{
    // check if the denominator is equal to 1
    if (rational->denominator == 1)
    {
        fprintf(file, "%d", rational->numerator);
    }
    else
    {
        fprintf(file, "%d/%d", rational->numerator, rational->denominator);
    }
}

bool equal(const Rational *num1, const Rational *num2)
{
    Rational num1cpy = copy_rational(num1);
    Rational num2cpy = copy_rational(num2);
    simplify(&num1cpy);
    simplify(&num2cpy);

    return (num1cpy.numerator == num2cpy.numerator && num1cpy.denominator == num2cpy.denominator);
}

int compare(const Rational *num1, const Rational *num2)
{
    Rational num1cpy = copy_rational(num1);
    Rational num2cpy = copy_rational(num2);
    simplify(&num1cpy);
    simplify(&num2cpy);
    // num1 = a/b, num2 = c/d
    int a = num1cpy.numerator * num2cpy.denominator; // a * d
    int b = num1cpy.denominator * num2cpy.numerator; // b * c
    // if a*d < b*c, num1 < num2
    if (a < b)
    {
        // num1 less than num2
        return -1;
    }
    else if (a > b)
    {
        // num 1 is greater than num 2
        return 1;
    }
    else
    {
        // equal
        return 0;
    }
}
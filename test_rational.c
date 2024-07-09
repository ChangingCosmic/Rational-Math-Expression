#include "rational.h"

int read_rational(FILE *, int *, int *, int *, int *, char[]);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Not enough arguments.");
        return -1;
    }
    FILE *f2 = fopen(argv[argc - 1], "w");

    for (int i = 1; i < argc - 1; i++)
    {
        FILE *f1 = fopen(argv[i], "r");

        // if the files are null
        if (NULL == f1 || NULL == f2)
        {
            printf("Error opening file.");
            continue;
        }

        int n1, d1, n2, d2;
        char operator[3]; // Extend to accommodate longer operators

        while (read_rational(f1, &n1, &d1, &n2, &d2, operator) > 0)
        {
            Rational rat1 = create_rational(n1, d1);
            Rational rat2 = create_rational(n2, d2);

            char sign[3] = ""; // Will store the actual operator

            // Determines if it's something like <=, >=, !=, also catches ==
            sign[0] = operator[0];
            if (operator[1] == '=')
            {
                sign[1] = operator[1];
                sign[2] = '\0'; // Null terminate the string
            }
            else
            {
                sign[1] = '\0';
            }

            Rational ans;
            int trueFalse = 0;
            bool boolTrueFalse = false;

            // determines what operator to use
            switch (sign[0])
            {
            case '+':
                ans = add(&rat1, &rat2);
                break;
            case '-':
                ans = subtract(&rat1, &rat2);
                break;
            case '*':
                ans = multiply(&rat1, &rat2);
                break;
            case '/':
                ans = divide(&rat1, &rat2);
                break;
            case '!': // Added case for '!'
                boolTrueFalse = !equal(&rat1, &rat2);
                break;
            case '=':
                boolTrueFalse = equal(&rat1, &rat2);
                break;
            case '>':
            case '<':
                trueFalse = compare(&rat1, &rat2);
                break;
            }

            print(f2, &rat1);
            fprintf(f2, " %s ", sign); // Use %s to print the actual operator
            print(f2, &rat2);
            fprintf(f2, "\t: ");

            // determines what type of answer to display
            switch (sign[0])
            {
            case '>':
                if (sign[1] == '=')
                {                       // Greater than or equal to
                    if (trueFalse >= 0) // Comparison result is 0 or positive
                        fprintf(f2, "true");
                    else
                        fprintf(f2, "false");
                }
                else
                {                      // Greater than
                    if (trueFalse > 0) // Comparison result is positive
                        fprintf(f2, "true");
                    else
                        fprintf(f2, "false");
                }
                break;
            case '<':
                if (sign[1] == '=')
                {                       // Less than or equal to
                    if (trueFalse <= 0) // Comparison result is 0 or negative
                        fprintf(f2, "true");
                    else
                        fprintf(f2, "false");
                }
                else
                {                      // Less than
                    if (trueFalse < 0) // Comparison result is negative
                        fprintf(f2, "true");
                    else
                        fprintf(f2, "false");
                }
                break;
            case '!':
                if (sign[1] == '=')
                {                               // Not equal to
                    if (boolTrueFalse == false) // Comparison result is not 0
                        fprintf(f2, "false");
                    else
                        fprintf(f2, "true");
                }
                break;
            case '=':
                if (true == boolTrueFalse)
                    fprintf(f2, "true");
                else
                    fprintf(f2, "false");
                break;
            default:
                print(f2, &ans);
                break;
            }
            fprintf(f2, "\n");
        }
        fclose(f1);
    }
    fclose(f2);
}

int read_rational(FILE *f1, int *n1, int *d1, int *n2, int *d2, char op[])
{
    char line[100];
    char *s = fgets(line, 99, f1);
    if (s == NULL)
    {
        return 0;
    }
    else
    {
        // 1. rational1 op rational2
        if (sscanf(line, "%d/%d %s %d/%d", n1, d1, op, n2, d2) == 5)
        {
            return 5;
        }
        // 2. num1 op rational2
        else if (sscanf(line, "%d %s %d/%d", n1, op, n2, d2) == 4)
        {
            *d1 = 1;
            return 4;
        }
        // 3. rational1 op num2
        else if (sscanf(line, "%d/%d %s %d", n1, d1, op, n2) == 4)
        {
            *d2 = 1;
            return 4;
        }
        // 4. num1 op num2
        else if (sscanf(line, "%d %s %d", n1, op, n2) == 3)
        {
            *d1 = 1;
            *d2 = 1;
            return 3;
        }
        // 5. Error!
        else
        {
            return -1;
        }
    }
}
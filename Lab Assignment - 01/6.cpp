/// Write a program to find the root of the equation x3 - 6x + 4 = 0, correct to 3 decimal places, by using Newton-Raphson method.
/// C221060

#include<bits/stdc++.h>
using namespace std;

    /*

    Newton-Raphson Method

    Example: Given, x^3 - 6x + 4 = 0
    Let, f(x) = x^3 - 6x + 4
    Thus, f'(x) = 3x^2 - 6 (first derivative)
    Fix two point, x1, and x2
    Assume x1 initially and find x2 by the formula,
    x2 = x1 - f(x1) / f'(x1)

    Replace x1 by x2 and find x2 again,
    Repeat this process until fabs(x2 -x1 ) < E

    */

double error = .005;

/// Finding f(x1)
double f_x1(double x1)
{
    return (x1 * x1 * x1) - (6 * x1) + 4;
}

/// Finding f'(x1)
double f_prime(double x1)
{
    return (3 * x1 * x1) - 6.0;
}
int main()
{
    double x1 = 0; /// Assumption
    double x2 = x1 - ( f_x1(x1) / f_prime(x1) );
    while( fabs(x2 - x1) > error )
    {
       x1 = x2;
       x2 = x1 - ( f_x1(x1) / f_prime(x1) );
    }

    cout << "The result is: " << fixed << setprecision(4) << x1 << endl;

    return 0;
}

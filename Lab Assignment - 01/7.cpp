/// Write a program to find the root of the equation x3 - x + 2 = 0, correct to 3 decimal places, by using false position method.
/// C221060

#include<bits/stdc++.h>
using namespace std;

    /*

    False Position method

    For root point(x,y), x = x0 and y = 0;
    At first, we should decide initial value of x1 and x2

    By placing root point to line equation ((f (x2) – f (x1)) / (x2 - x1) = (y- f (x1)) / (x - x1))
    we find,
    x0 = x1- (f(x1) (x2-x1) ) / (f (x2) – f (x1))

    If f (x0) * f (x1) < 0 set x2 = x0 otherwise set x1 = x0
    Repeat until the absolute difference between two successive x0 is less then E

    */

double error = .00005;

double f_x(double x)
{
    return ((x * x * x) - x + 2) * 1.00;
}

int main()
{
    double x1 = -2.0, x2 = 1.0;

    double x0 = x1 - ( ( f_x(x1) * (x2- x1) ) / ( f_x(x2) - f_x(x1) ) );
    if( f_x(x1) * f_x(x0) < 0.0 ) x2 = x0;
    else x1 = x0;
    double x0_prev = x0;
    x0 = x1 - ( ( f_x(x1) * (x2- x1) ) / ( f_x(x2) - f_x(x1) ) );
    while( abs(x0_prev - x0) > error )
    {
        if( f_x(x1) * f_x(x0) < 0.0 ) x2 = x0;
        else x1 = x0;
        x0_prev = x0;
        x0 = x1 - ( ( f_x(x1) * (x2- x1) ) / ( f_x(x2) - f_x(x1) ) );
    }

    cout << fixed << setprecision(4) << x0 << endl;

    return 0;
}

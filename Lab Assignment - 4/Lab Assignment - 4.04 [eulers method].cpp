/// C221060

/*

4. Write a program to solve the following Differential Equation by using Euler�s method.
        dy / dx = x3 + y,  y (0) = 1. Compute y (0.02) taking h = 0.01.

*/

#include <bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    return (x * x * x) + y;
}
int main()
{
    double x, y, h, point;
    cout << "Enter x0 :";
    cin >> x;
    cout << "Enter y0 :";
    cin >> y;
    cout << "Enter h:";
    cin >> h;
    cout << "Enter x to compute y(x):";
    cin >> point;
    double in = x, ans = y;
    do
    {
        in += h;
        ans = ans + (1.00 * h * fun(in, ans));
    }
    while (fabs(in - point) > 0.00001);

    cout << endl;
    cout << "y(" << point << ") = " << ans << endl;
}

/*

Input:

0 1 0.01 0.02

Output:

y(0.02) = 1.0201

*/

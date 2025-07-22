/// C221060


/*

5. Write a program to solve the following Differential Equation by using Runge – Kutta method.
       dy / dx = x + y, y (0) = 1.  Compute y (0.1) and y (0.2)  taking h = 0.1.

*/

#include<bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    return 1.00 * x + y;
}

int main()
{
    double x, y,h,point;
    cout << "Enter x0 : ";
    cin >> x;
    cout << "Enter y0 : ";
    cin >> y;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter x to compute y(x): ";
    cin >> point;
    double in = x,ans = y;
    do
    {
        double m1 = fun(in,ans);
        double m2 = fun(in  + (h/ 2.00), ans + (1.00 * m1 * h)/2.00 );
        double m3 = fun(in  + (h/ 2.00), ans + (1.00 * m2 * h)/2.00 );
        double m4 = fun(in + h, ans + (1.00 * m3 *h));
        double m = m1 + (2.0 * m2) + (2.0*m3) + m4;
        ans = ans + (m/ 6.00) * h;
        in += h;
    }
    while(fabs(in - point) > 0.00001);

    cout << "\n\n";
    cout << "y(" << point << ") = " << ans << endl;
}

/*

Input:

0 1 0.1 0.1

Output:

y(0.1) = 1.11034

*/

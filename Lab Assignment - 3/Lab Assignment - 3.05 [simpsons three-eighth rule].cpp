/// C221060

/*

5. Write a program to calculate the approximate area under the curve:

    y = f (x / (1 + x^2)) dx from a to b

using Simpson's 3/8 Rule.

Formula:

   I = (3h/8) * [(y0 + y_n) + 3(y1+y2+y4+y6+...+y_n-2+y_n-1) ) + 2(y3+y6+... +y_n-3) ]
where:
    h = (b - a) / n
    n must be a multiple of 3

*/

#include<bits/stdc++.h>
using namespace std;

double fun(double x)
{
    return x / (1 + x * x);
}

int main()
{
    double a, b;
    int n;

    cout << "Enter lower limit: ";
    cin >> a;
    cout << "Enter upper limit: ";
    cin >> b;
    cout << "Enter number of intervals (must be multiple of 3): ";
    cin >> n;

    double h = (b - a) / n;
    double sum = fun(a) + fun(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2.0 * fun(x);
        else
            sum += 3.0 * fun(x);
    }

    double result = (3.0 * h / 8.0) * sum;

    cout << "\nApproximate area is: " << result << endl;

    return 0;
}

/*

Input:

0
1
30

Output:

0.346574

*/

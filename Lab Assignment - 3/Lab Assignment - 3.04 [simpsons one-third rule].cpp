/// C221060

/*

Write a program to calculate the approximate area under the curve y = ∫ /2 e sinx dx by using Simpson’s 1/3
rule

*/

#include<bits/stdc++.h>
using namespace std;

double fun(double x)
{
    return exp(sin(x));
}

int main()
{
    double a, b;
    int n;

    cout << "Enter lower limit (radians): ";
    cin >> a;
    cout << "Enter upper limit (radians): ";
    cin >> b;
    cout << "Enter number of intervals (must be even): ";
    cin >> n;

    double h = (b - a) / n;
    double sum = fun(a) + fun(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + (i * h);
        if (i % 2 == 0)
            sum += 2 * fun(x);
        else
            sum += 4 * fun(x);
    }

    double result = (h / 3.0) * sum;

    cout << "\nApproximate area is: " << result << endl;

    return 0;
}

/*

Input:

0
1.5708
10

Output:

Approximate area is: 3.10439

*/

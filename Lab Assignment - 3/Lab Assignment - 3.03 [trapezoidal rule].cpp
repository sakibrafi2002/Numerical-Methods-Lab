/// C221060

/*

3. Write a program to calculate the approximate area under the curve y = ∫ 5 log 10 x dx
by using trapezoidal rule.

Theory:
I =h/2 [y0 + 2 (y1 + y2 + â€¦â€¦â€¦.  + yn-1) + yn]

*/


#include<bits/stdc++.h>
using namespace std;

double fun(double x) {
    return log10(x);
}

int main(){
    double a, b;
    int n;

    cout << "Lower Limit = ";
    cin >> a;
    cout << "Upper Limit = ";
    cin >> b;
    cout << "Number of intervals = ";
    cin >> n;

    double h = (b - a) / n;
    double sum = fun(a) + fun(b);

    for(int i = 1; i < n; i++){
        double x = a + (i * h);
        sum += (2 * fun(x));
    }

    double result = (h / 2.0) * sum;

    cout << "Approximate area is : "<< result << endl;

    return 0;
}

/*

Input:

1
5
10

Output:

Approximate area is : 1.75307

*/

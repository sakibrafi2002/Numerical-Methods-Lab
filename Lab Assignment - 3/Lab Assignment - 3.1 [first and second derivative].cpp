/// C221060

/*

1. The following values of f (x) are given.

x           1  2  3   4   5
y = f(x)    1  8  27  64  125

Write a program to find the first derivative and the second derivative of the function tabulated above at
the point x = 1.

*/

#include<bits/stdc++.h>
using namespace std;

void Print(vector <int> x)
{
    for(auto a : x){
        cout << a << ' ';
    }
    cout << endl;
}

int fact(int x)
{
    int ans = 1;
    for(int i=x; i>=2; i--){
        ans *= i;
    }
    return ans;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> x,y,d[n+5];
    cout << "Value of x : ";
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        x.push_back(t);
    }
    cout << "Value of y : ";
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        y.push_back(t);
    }

    d[0] = y;


    for(int i = 1; i < n; i++){
        for(int j = 1; j < d[i-1].size(); j++){
            d[i].push_back(d[i-1][j] - d[i-1][j-1]);
        }
    }


    double X;
    cout << "Enter the value of X: ";
    cin >> X;
    double h = x[1] - x[0];
    double u = ((X - x[0]) / h) * 1.0;

    double first_derivative = (1.0 / (h * 1.0)) * ( ((d[1][0] * 1.0) ) + ((( (2 * u) - 1 ) * (d[2][0] * 1.0) ) / fact(2) ) + ( ( ( (3.0*u*u) - (6.0 * u) + 2 ) * (d[3][0]*1.0) ) / fact(3) ) + ( ( ( (4*u*u*u) - (18*u*u) + (22*u) - 6) * (d[4][0] *1.0) ) / fact(4) ) );
    double second_derivative = (1.0 / (h*h*1.0)) * ( (d[2][0] * 1.0) + ( ( ( (6.0 * u) - 6 ) * (d[3][0] * 1.0) ) / fact(3) )  + ( ( ( (12.0*u*u) - (36.0 * u) + 22 ) * (d[4][0] * 1.0) ) / fact(4) ) );
    cout << "f'(1)  = " << first_derivative  << endl;
    std::cout << "f''(1) = " << second_derivative << endl;

    return 0;


}


/*

Input:

5
1 2 3 4 5
1 8 27 64 125
1

Output:

y = 4.913


*/

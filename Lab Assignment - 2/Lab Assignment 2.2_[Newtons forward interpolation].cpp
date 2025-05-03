/// C221060

/*
2. The following values of f (x) are given.

x          1  2  3   4    5
y = f(x)   1  8  27  64   125

Write a program to find the values of y when x = 1.7 by using Newton&#39;s forward interpolation
formula.
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
    double ans = d[0][0] * 1.0;

    for(int i=1; i<=n-1; i++){
        double t = u;
        for(int j=1; j<i; j++){
            t *= (u - double(j));
        }
        t *= (double)(d[i][0]);
        t /= (double)(fact(i));
        ans += double(t);
    }

    cout << "y = " << ans << endl;

    return 0;

}


/*

Input:

5
1 2 3 4 5
1 8 27 64 125
1.7

Output:

y = 4.913


*/

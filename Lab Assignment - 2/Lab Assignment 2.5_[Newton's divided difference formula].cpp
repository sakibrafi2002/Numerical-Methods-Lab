/// C221060

/*

5. The following values of f (x) are given. Prepare the divided difference table for the following data

    x          1  3   4   6    10
    y = f(x)   0  18  58  190  920

Write a program to find the values of y when x = 2.7 by using Newton's divided difference formula.

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    vector<double> x,y;
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

    vector<double>d[n+5];
    d[0] = y;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < d[i-1].size(); j++){
            double t1 = d[i-1][j] - d[i-1][j -1];
            double t2 = x[j - 1 + i] - x[j - 1];
            double t = t1 / t2;
            d[i].push_back(t);
        }
    }


    cout << "X = ";
    double X,ans = d[0][0];
    cin >> X;
    for(int i = 1; i < n; i++){
        double t = 1.0;
        for(int j = 1; j <= i; j++){
            t *= (X - x[j - 1]);
        }
        t *= d[i][0];
        ans += t;
    }

    cout << "Y = " << ans << endl;

    return 0;

}


/*

Input:

5
1 3 4 6 10
0 18 58 190 920
2.7

Output:




*/

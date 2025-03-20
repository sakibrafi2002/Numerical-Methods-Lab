/*
Write a program to find all the roots of the equation x3 - 6x + 4 = 0,
correct to 3 decimal places. [Use Newton-Raphson method with deflation].
*/
/// C221060

#include<bits/stdc++.h>
using namespace std;

double error = 0.0001;

double fx(double x, vector<double>a)
{
    int n = a.size();
    double result = 0.0;
    for(int i = n; i >= 0; i--){
        result += (1.0 * a[i] * pow(x,i));
    }
    return result;
}

double dfx(double x, vector<double>a)
{
    int n = a.size();
    double result = 0.0;
    for(int i = n; i >= 1; i--){
        result += (1.0 * a[i] * (pow(x,i-1)));
    }
    return result;

}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    vector<double> a(n+1);
    for(int i = n; i >= 0; i--){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    vector<double> ans;
    double x0 = 1.0;

    while(n > 1){
        double x1 = x0;
        double x2 = x1 - ( fx(x1, a) / dfx(x1, a));

        while(fabs(x2 - x1) > error){
            x1 = x2;
            x2 = x1 - ( fx(x1, a) / dfx(x1, a));
        }

        ans.push_back(x2);

        vector<double>b = a;
        b[n] = 0;
        for(int i = n-1; i >= 0; i--){
            b[i] = a[i+1] + (x2 * b[i+1]);
        }
        b.pop_back();
        a = b;
        n--;
    }

    ans.push_back(-a[0]/a[1]);

    for(int i = 0; i < ans.size(); i++){
        cout << "Root " << (i+1) << " : " << fixed << setprecision(3) << ans[i] << endl;
    }


    return 0;
}


/*

input:

3
1
0
-6
4

output:

Root 1 : 0.732
Root 2 : 2.000
Root 3 : -2.732

*/

/// Write a program to find the root of the equation x3 – 9x + 1 = 0, correct to 3 decimal places, by using the bisection method.
/// C221060

#include<bits/stdc++.h>
using namespace std;

double error = .0005;

double calc(double x)
{
    return ( (x * x * x) - (9.0 * x) + 1 );
}

int main()
{
    double boro = 3.0, choto = 2.0;

    while(fabs(boro - choto) >= error)
    {
        double mid = (boro + choto) / 2.0;
        double cur = calc(mid);
        if(cur < 0.0){
            choto = mid;
        }
        else boro = mid;
    }

    cout << fixed << setprecision(3) << boro << endl;

    return 0;

}

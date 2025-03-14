/// Write a program to find the root of the equation x3 – 9x + 1 = 0, correct to 3 decimal places, by using the bisection method.
/// C221060

#include<bits/stdc++.h>
using namespace std;

double error = .0001;

bool calc(double x)
{
    double xx = ( (x * x * x) - (9.0 * x) + 1.0 );
    if(xx < 0.0) return true;
    else return false;
}

int main()
{
    double boro = 3.0, choto = 1.0;

    while(fabs(boro - choto) >= error)
    {
        double mid = (boro + choto) / 2.0;
        if(calc(mid)){
            choto = mid;
        }
        else boro = mid;
    }

    cout << fixed << setprecision(3) << choto << endl;

    return 0;

}

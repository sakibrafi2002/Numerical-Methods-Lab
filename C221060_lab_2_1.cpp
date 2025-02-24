/// Write a program to evaluate the polynomial function using Horner's rule
/// C221060

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the value of n = ";
    int n,x;
    cin >> n;

    vector<int> a(n+5),p(n+5);
    for(int i = n; i >= 0; i--){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Value of x = ";

    cin >> x;

    p[n+1] = 0;

    for(int i = n; i >= 0; i--){
        p[i] = (p[i+1] * x) + a[i];
    }

    cout << "The answer is = " << p[0] << endl;

    return 0;

}

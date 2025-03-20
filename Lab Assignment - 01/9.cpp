/// Write a program to find the quotient polynomial q(x) such that p(x) = (x - 2) q(x) where the polynomial p(x) = x3 - 5x2 + 10x - 8 = 0 has a root at x = 2.
/// C221060

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cout << "n = ";
    cin >> n;
    cout << "x = ";
    cin >> x;
    vector<int>a(n+5),b(n+5);
    for(int i = n; i>=0; i--)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    b[n] = 0;
    for(int i = n-1; i >= 0; i--){
        b[i] = a[i+1] + (x * b[i+1]);
    }

    cout << "\nThe Quotient Polynomial q(x) is, \n";

    for(int i = n-1; i >= 0; i--){
        if(b[i] == 0){
            continue;
        }
        if(i == n-1){
            cout << b[i] << "x^" << i << " ";
            continue;
        }
        if(i == 0){
            if(b[i] >= 0) cout << "+ " << b[i] << " ";
            else cout << "- " << abs(b[i]) << " ";
            continue;
        }
        else{
            if(b[i] >= 0 ) cout << "+ "  << b[i] << "x^" << i << " ";
            else cout << "- " << abs(b[i]) << "x^" << i << " ";
        }
    }
    cout << "= 0" << endl;

    return 0;
}


/*

input:

3
2
1
-5
10
8

output:

The Quotient Polynomial q(x) is,
1x^2 - 3x^1 + 4 = 0

*/

/// C221060

/*

The following values of f (x) are given.


     x              1    2     3       4       5
  y = f(x)          1    8     27      64      125

Write a program to find difference table for the above values.

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
    //Print(d[0]);

    for(int i = 1; i < n; i++){
        for(int j = 1; j < d[i-1].size(); j++){
            d[i].push_back(d[i-1][j] - d[i-1][j-1]);
        }
    }

    for(int i = 0; i < n; i++){
        cout << "D^" << i << " : ";
        Print(d[i]);
    }

}


/*

Input:

5
1 2 3 4 5
1 8 27 64 125

Output:

D^0 : 1 8 27 64 125
D^1 : 7 19 37 61
D^2 : 12 18 24
D^3 : 6 6
D^4 : 0

*/

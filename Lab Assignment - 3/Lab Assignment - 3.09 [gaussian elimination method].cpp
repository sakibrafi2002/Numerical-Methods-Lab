/// C221060

/*

Write a program to solve the following system of linear equations by using Gaussian Elimination method.
          2x +  y  +   z = 10
           x  + 4y + 9z = 16
          3x + 2y + 3z = 18

*/


#include<bits/stdc++.h>
using namespace std;


int main()
{

    double A[5][6];

    for( int i = 1 ; i <= 3; i++)
    {
        for( int j = 1 ; j <= 3; j++)
        {
            cout << "a" << i << j << " : ";
            cin >> A[i][j];
        }
        cout << "Enter b" << i << ": ";
        cin >> A[i][4];
    }

    double m1 = ( - ((A[2][1] * 1.00)  / A[1][1]));
    double m2= ( - ((A[3][1] * 1.00)  / A[1][1]));
    for( int i = 1; i <= 4; i++)
    {
        double t1 = A[1][i] * m1;
        double t2 = A[1][i] * m2;
        A[2][i] += t1;
        A[3][i] += t2;
    }

    double m3 = ( - ((A[3][2] * 1.00) / A[2][2]));
    for( int i = 1; i <= 4; i++)
    {
        double t = A[2][i] * m3;
        A[3][i] += t;
    }

    vector<double>ans(4);
    ans[3] = (A[3][4]*1.00) / A[3][3];
    ans[2] = (A[2][4] - (A[2][3] * ans[3])) / (1.00 * A[2][2]);
    ans[1] = (A[1][4] - (A[1][3] * ans[3]) - (A[1][2] * ans[2])) / (1.00 * A[1][1]);

    cout << "\n\n";
    cout << "x1 = " << ans[1] << endl
         << "x2 = " << ans[2] << endl
         << "x3 = " << ans[3] << endl;


    return 0;
}


/*

Input:

2 1 1 10
1 4 9 16
3 2 3 18

Output:

x1 = 7
x2 = -9
x3 = 5

*/

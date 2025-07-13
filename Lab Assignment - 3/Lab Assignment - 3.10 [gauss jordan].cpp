///C221060

/*

10. Write a program to solve the following system of linear equations by using Gauss-Jordan Elimination method.
           x  + 2y +  z = 8
           2x + 3y + 4z = 20
           4x + 3y + 2z = 16

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{

    double A[6][6];

    for( int i = 1 ; i <= 3; i++)
    {
        for( int j = 1 ; j <= 3; j++)
        {
            cout << "a" << i << j << " = ";
            cin >> A[i][j];
        }
        cout << "b" << i << " = ";
        cin >> A[i][4];
    }
    for( int i = 1; i <= 3 ; i++)
    {
        ///Normalize ith eqn
        double div = A[i][i];
        for( int j = 1 ; j <= 4; j++)
        {
            A[i][j] /= (1.00 * div);
        }

        ///Elimination
        for( int j= 1 ; j <= 3; j++)
        {
            if(i == j)
                continue;
            double sub = (-1.00) * A[j][i];
            for(int k = 1; k <= 4; k++)
            {
                A[j][k] += (sub * A[i][k]);
            }
        }

    }


    cout << "\n\n";
    for(int i= 1; i <= 3; i++)
    {
        cout << "x" << i << " = " << A[i][4] << endl;
    }
}

/*

Input:

1 2 1 8
2 3 4 20
4 3 2 16

Output:

x1 = 1
x2 = 2
x3 = 3

*/

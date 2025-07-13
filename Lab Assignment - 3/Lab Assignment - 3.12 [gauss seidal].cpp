/// C221060

/*

12. Write a program to solve the following system of linear equations by using Gauss-Seidel method.

        10x1  +   x2   +    x3     = 12
         2x1  + 10x2   +    x3     = 13
         2x1  +   2x2  +  10x3     = 14



remember:
For each row, the absolute value of the diagonal element should be greater than the sum of absolute values of the other elements in the equation. i.e.
		| aii | >  sum(| aij |) for all j and i != j


*/


#include<bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    cout << "Enter number of Unknowns = ";
    cin >> n;
    vector<vector<double>>A(n+2, vector<double>(n+2, 0));

    for( int i = 1 ; i <= n; i++)
    {
        for( int j = 1 ; j <= n; j++)
        {
            cout << "a" << i << j << " = ";
            cin >> A[i][j];
        }
        cout << "b" << i << " = ";
        cin >> A[i][n + 1];
    }

    vector<double>assumption(n + 2);

    for( int i = 1; i <= n; i++)
        assumption[i] = 0.0;


    int x = 0;
    while(++x <= 80)
    {
        for( int i = 1; i <= n ; i++)
        {
            double temp = A[i][n + 1] * 1.00;
            for( int j = 1; j<= n; j++)
            {
                if(i != j)
                {
                    temp -= (1.00 * A[i][j] * assumption[j]);
                }
            }

            temp /= (1.00 * A[i][i]);
            assumption[i] = temp;

        }

    }

    cout << "\n\n";
    for( int i = 1; i <= n; i++)
    {
        cout << "x" << i << " = " << assumption[i] << endl;
    }
}


/*

Input:

3
83 11 -4 95
7 52 13 104
2 8 29 71


Output:

x1 = 1.06116
x2 = 1.35696
x3 = 2.00076

Input:

3
10 1 1 12
2 10 1 13
2 2 10 14

Output:

x1 = 1
x2 = 1
x3 = 1

*/

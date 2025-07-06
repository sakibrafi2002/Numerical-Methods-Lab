/// C221060

/*

7. Write a program to solve the following system of linear equations by using Matrix inversion method.

    x + y + z = 1
    x + 2y + 3z = 6
    x + 3y + 4z = 6

*/

#include <iostream>
using namespace std;

int main()
{
    double A[3][3], B[3];
    cout << "Matrix A:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }


    cout << "Matrix B:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "B[" << i+1 << "]: ";
        cin >> B[i];
    }

    //determinant
    double det =
        A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) -
        A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) +
        A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    if (det == 0)
    {
        cout << "Matrix is singular. No unique solution.\n";
        return 1;
    }

    //inverse of A (adjoint / det)
    double inv[3][3];

    inv[0][0] =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]) / det;
    inv[0][1] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]) / det;
    inv[0][2] =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]) / det;

    inv[1][0] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]) / det;
    inv[1][1] =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]) / det;
    inv[1][2] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]) / det;

    inv[2][0] =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]) / det;
    inv[2][1] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]) / det;
    inv[2][2] =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]) / det;

    //  A^-1 * B
    double x[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            x[i] += inv[i][j] * B[j];


    cout << "\nSolution:\n";
    cout << "x = " << x[0] << endl;
    cout << "y = " << x[1] << endl;
    cout << "z = " << x[2] << endl;

    return 0;
}

/*

Input:

1 1 1
1 2 4
1 3 4
1 6 6

Output:

x = -0.666667
y = 0
z = 1.66667

*/

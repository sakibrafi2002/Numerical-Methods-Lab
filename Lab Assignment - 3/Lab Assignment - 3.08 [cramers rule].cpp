/// C221060

/*

8. Write a program to solve the following system of linear equations by using Cramer’s Rule:

           27x +  6y –  z   =  85
            6x + 15y + 2z   = 72
             x +   y + 54z  = 110



*/

#include <iostream>
using namespace std;

double DET(double A[3][3])
{
    return A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) -
           A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) +
           A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
}

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
    double det = DET(A);

    if (det == 0)
    {
        cout << "Matrix is singular. No unique solution.\n";
        return 1;
    }

    // Create matrices for Dx, Dy, Dz
    double ax[3][3], ay[3][3], az[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ax[i][j] = (j == 0) ? B[i] : A[i][j];
            ay[i][j] = (j == 1) ? B[i] : A[i][j];
            az[i][j] = (j == 2) ? B[i] : A[i][j];
        }
    }

    double Dx = DET(ax);
    double Dy = DET(ay);
    double Dz = DET(az);


    cout << "\nSolution:\n";
    cout << "x = " << (Dx / det) << endl;
    cout << "y = " << (Dy / det) << endl;
    cout << "z = " << (Dz / det) << endl;

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

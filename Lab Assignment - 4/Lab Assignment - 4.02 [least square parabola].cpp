#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to perform Gaussian elimination
void gaussianElimination(vector<vector<double>> &a, vector<double> &x, int n) {
    for (int i = 0; i < n; i++) {
        // Partial pivoting
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[i][i])) {
                for (int j = 0; j <= n; j++) {
                    swap(a[i][j], a[k][j]);
                }
            }
        }

        // Make diagonal elements 1
        double diag = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= diag;
        }

        // Eliminate below
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    // Extract solution
    for (int i = 0; i < n; i++) {
        x[i] = a[i][n];
    }
}

int main() {
    int dataPoints, degree;
    cout << "Enter number of data points: ";
    cin >> dataPoints;
    cout << "Enter degree of polynomial: ";
    cin >> degree;

    vector<double> X(dataPoints), Y(dataPoints);
    cout << "Enter x and y values:\n";
    for (int i = 0; i < dataPoints; i++) {
        cin >> X[i] >> Y[i];
    }

    int m = degree;
    vector<vector<double>> mat(m + 1, vector<double>(m + 2, 0.0));

    // Compute sums
    vector<double> sumX(2 * m + 1, 0.0);
    for (int i = 0; i < 2 * m + 1; i++) {
        for (int j = 0; j < dataPoints; j++) {
            sumX[i] += pow(X[j], i);
        }
    }

    vector<double> sumXY(m + 1, 0.0);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < dataPoints; j++) {
            sumXY[i] += pow(X[j], i) * Y[j];
        }
    }

    // Fill normal equations
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            mat[i][j] = sumX[i + j];
        }
        mat[i][m + 1] = sumXY[i];
    }

    // Solve
    vector<double> coeff(m + 1);
    gaussianElimination(mat, coeff, m + 1);

    cout << "\nPolynomial coefficients:\n";
    for (int i = 0; i <= m; i++) {
        cout << "a" << i << " = " << coeff[i] << "\n";
    }

    cout << "\nEquation: y = ";
    for (int i = 0; i <= m; i++) {
        cout << coeff[i];
        if (i > 0) cout << "*x^" << i;
        if (i < m) cout << " + ";
    }
    cout << endl;

    return 0;
}




/*

Input:

4
2
2 1.4
4 2.0
6 2.4
8 2.8

Output:

Polynomial coefficients:
a0 = 0.75
a1 = 0.355
a2 = -0.0125

Equation: y = 0.75 + 0.355*x^1 + -0.0125*x^2



*/

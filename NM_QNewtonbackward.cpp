#include<bits/stdc++.h>
using namespace std;

double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) fact *= i;
    return fact;
}

int main()
{
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {1, 8, 27, 64, 125};
    int n = x.size();
    double xVal = 1.7;

    vector<vector<double>> diff(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    cout << "Forward Difference Table:\n";

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << diff[i][j] << "\t";
        cout << endl;
    }

    double h = x[1] - x[0];
    double p = (xVal - x[0]) / h;
    double result = diff[0][0];
    double p_term = 1.0;

    for (int i = 1; i < n; i++) {
        p_term *= (p - (i - 1));
        result += (p_term * diff[0][i]) / factorial(i);
    }

    cout << fixed << setprecision(4);
    cout << "\nValue of f(" << xVal << ") = " << result << endl;

    return 0;
}

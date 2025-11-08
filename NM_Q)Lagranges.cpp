#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {1, 8, 27, 64, 125};
    int n = x.size();
    double xVal = 2.5;
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term *= (xVal - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    cout << fixed << setprecision(6);
    cout << "Value of f(" << xVal << ") = " << result << endl;

    return 0;
}

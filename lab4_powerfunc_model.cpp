#include<bits/stdc++.h>
using namespace std;
int main()
 {
    const int n = 4;
    double x[n] = {2, 10, 26, 61};
    double y[n] = {600, 500, 400, 350};

    double Y[n];
    double Sx = 0.0, SY = 0.0, SxY = 0.0, Sx2 = 0.0;

    // Convert y to ln(y) and compute summations
    for (int i = 0; i < n; i++)
    {
        Y[i] = log(y[i]); // natural log
        Sx  += x[i];
        SY  += Y[i];
        SxY += x[i] * Y[i];
        Sx2 += x[i] * x[i];
    }
    // Calculate b
    double numerator_b = (n * SxY) - (Sx * SY);
    double denominator_b = (n * Sx2) - (Sx * Sx);
    double b = numerator_b / denominator_b;

    // Calculate A (which is ln(a))
    double A = (SY - b * Sx) / n;
    double a = exp(A);

    // Print the results
    std::cout << "Best fit values:\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "y = " << a << " * e^(" << b << " * x)\n";

    return 0;
}

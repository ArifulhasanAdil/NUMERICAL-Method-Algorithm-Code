#include <bits/stdc++.h>
using namespace std;

// Function definition
double f(double x) {
    return x * x * x - 5 * x * x - 29;
}

// Truncate to 3 decimals
double truncate3(double x) {
    return floor(x * 1000) / 1000;
}

int main() {
    double a = 0, b = 0, x0, x1, x2;
    bool found = false;
    int iter = 1;
    const double tol = 1e-3;

    // Automatically find valid interval
    for (double i = -10; i <= 10; i ++) {
        if (f(i) * f(i + 1) < 0) {
            a = i;
            b = i + 1;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No valid interval found.\n";
        return 0;
    }

    cout << fixed << setprecision(3);
    cout << "Automatically found valid interval: a = " << a << ", b = " << b << "\n\n";

    // Table header
    cout << "Iter\t x0\t\t x1\t\t f(x0)\t\t f(x1)\t\t x2\n";
    cout << "------------------------------------------------------------------\n";

    x0 = a;
    x1 = b;

    while (true) {
        double fx0 = f(x0);
        double fx1 = f(x1);

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        x2 = truncate3(x2);

        cout << iter++ << "\t " << x0 << "\t " << x1 << "\t "
             << fx0 << "\t " << fx1 << "\t " << x2 << "\n";

        if (fabs(x2 - x1) < tol || fabs(f(x2)) < tol)
            break;

        x0 = x1;
        x1 = x2;
    }
    cout << "\nThe root of the equation x^3 - 5x^2 - 29 = 0 is approximately: " << x2 << endl;

    return 0;
}

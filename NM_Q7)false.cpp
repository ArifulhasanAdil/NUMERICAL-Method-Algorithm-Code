#include <iostream>
#include <cmath>
using namespace std;

// Function f(x) = x^3 - x + 2
double f(double x) {
    return x*x*x - x + 2;
}

int main() {
    double a = -3, b = 0;       // Initial guesses
    double c;                    // Root
    double tol = 0.001;          // Tolerance for 3 decimal places
    int maxIter = 100;           // Maximum iterations

    if (f(a) * f(b) > 0) {
        cout << "Choose different initial guesses. No root in this interval." << endl;
        return 0;
    }

    int iter = 0;
    while (iter < maxIter) {
        c = (a*f(b) - b*f(a)) / (f(b) - f(a)); // False position formula

        if (fabs(f(c)) < tol) break;           // Stop if root is accurate enough

        if (f(a) * f(c) < 0)
        {
            b = c;  // Root is in [a, c]
        }
        else
        {
            a = c;  // Root is in [c, b]
        }

        iter++;
    }

    cout << "Root: " << c << " (after " << iter << " iterations)" << endl;

    return 0;
}

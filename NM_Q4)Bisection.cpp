#include<bits/stdc++.h>
#include <cmath>
using namespace std;

// Define function given in QUE f(x) = x^3 - 9x + 1
double f(double x) {
    return (x * x * x) - ( 9*x) + 1;
}
// Truncate to 3 decimal place
double truncate3(double num) {
    return trunc(num * 1000) / 1000.0;
}

int main() {
    double a = 0, b = 0, mid;
    double error = 0.001;
    // Automatically find valid interval [a,b]
    bool found = false;
    for (int i = 0; i < 10; i++) {
        if (f(i) * f(i + 1) < 0) {
            a = i;
            b = i + 1;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No root found in the given range.\n";
        return 0;
    }

    cout << "Automatically found valid interval: a = " << a << ", b = " << b << endl;
    cout << fixed << setprecision(3);
    cout << "\nIter\t    a\t b\t f(a)\t f(b)\t mid\t f(mid)\n";
    cout << "---------------------------------------------------------------\n";

    int iter = 1;
    while ((b - a) >= error) {
        mid = (a + b) / 2.0;
        double fmid = f(mid);
        double fmid_display = truncate3(fmid);

        cout << iter << "\t  " << a << "\t  " << b
             << "\t  " <<f(a)<< "\t"<<f(b)<< "\t" << mid << "\t" << fmid_display << endl;

        if (fabs(fmid) < error)  // use fabs() instead of direct equality
            break;

        if (f(a) * fmid < 0)
            b = mid;
        else
            a = mid;

        iter++;
    }
    cout << "\n The root of the equation x^3 - 9x + 1 = 0 is approximately: "
         << truncate3(mid) << endl;

    return 0;
}

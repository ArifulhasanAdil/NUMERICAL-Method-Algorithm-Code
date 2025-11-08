#include<bits/stdc++.h>
using namespace std;
//  f(x) = x^3 - 6x + 4
double f(double x)
{
    return (x * x * x) - (6 * x) + 4;
}
// Derivative f'(x) = 3x^2 - 6
double df(double x)
{
    return (3 * x * x) - 6;
}

double truncate3(double num)
{
    return trunc(num * 1000) / 1000.0;
}
int main() {
    double a = 0, b = 0, x0, x1;
    double error = 0.001;
    bool found = false;

    // Find valid [a, b]
    for (int i = 0; i < 10; i++) {
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

    cout << "Automatically found valid interval: a = " << a << ", b = " << b << endl;

    // initially Start from x0 = a
    x0 = a;
    int iter = 1;

    cout << "\nIter\t\tx0\t\tf(x0)\t\tf'(x0)\t\tx1\n";
    cout << "--------------------------------------------------------------\n";

    while (true) {
        double fx = f(x0);
        double dfx = df(x0);
        x1 = x0 - (fx / dfx);

        cout << iter++ << "\t\t"
             << truncate3(x0) << "\t\t"
             << truncate3(fx) << "\t\t"
             << truncate3(dfx) << "\t\t"
             << truncate3(x1) << endl;

        if (fabs(x1 - x0) < error)
            break;

        x0 = x1;
    }

    cout << "\n The root of x^3 - 6x + 4 = 0 is : " << truncate3(x1) << endl;

    return 0;
}

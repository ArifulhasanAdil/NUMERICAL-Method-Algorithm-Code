#include<bits/stdc++.h>
using namespace std;

// dy/dx = y - x
double f(double x, double y)
{
    return y - x;
}
int main() {
    double x0 = 0.0, y0 = 1.0;
    double x_end = 0.5;
    double h = 0.1;              // Step size

    double x = x0;
    double y = y0;

    cout << "x\t\ty" << endl;
    cout << x << "\t\t" << y << endl;

    while (x < x_end) {
        y = y + h * f(x, y);   // Euler's formula
        x = x + h;
        cout << x << "\t\t" << y << endl;
    }
    return 0;
}


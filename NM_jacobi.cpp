#include<bits/stdc++.h>
using namespace std;

int main() {
    float x0 = 0, y0 = 0, z0 = 0;
    float x1, y1, z1;
    float e = 0.0001;
    int i = 1, maxIter;

    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    cout << "\nIteration\t x\t\t y\t\t z" << endl;

    do {
        x1 = (95 - 11*y0 + 4*z0) / 83;
        y1 = (71 - 3*x0 - 29*z0) / 8;
        z1 = (104 - 7*x0 - 52*y0) / 13;

        cout << i << "\t\t "
             << x1 << "\t "
             << y1 << "\t "
             << z1 << endl;

        if (fabs(x1 - x0) < e && fabs(y1 - y0) < e && fabs(z1 - z0) < e)
            break;

        x0 = x1;
        y0 = y1;
        z0 = z1;
        i++;

    } while (i <= maxIter);

    cout << "\nApproximate Solution:" << endl;
    cout << "x = " << x1 << endl;
    cout << "y = " << y1 << endl;
    cout << "z = " << z1 << endl;

    return 0;
}

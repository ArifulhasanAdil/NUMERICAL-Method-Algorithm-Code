#include<bits/stdc++.h>
using namespace std;

int main() {
    float x1 = 0, x2 = 0, x3 = 0;
    int maxIter;

    cout << "Enter number of iterations: ";
    cin >> maxIter;

    cout << "\nIteration"
         << setw(12) << "x1"
         << setw(12) << "x2"
         << setw(12) << "x3" << endl;

    cout << fixed << setprecision(6);

    for (int i = 1; i <= maxIter; i++) {
        x1 = (12 - x2 - x3) / 10;
        x2 = (13 - 2*x1 - x3) / 10;
        x3 = (14 - 2*x1 - 2*x2) / 10;

        cout << setw(5) << i
             << setw(12) << x1
             << setw(12) << x2
             << setw(12) << x3 << endl;
    }

    cout << "\nFinal Solution:\n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;

    return 0;
}

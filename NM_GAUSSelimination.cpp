#include <iostream>
using namespace std;
int main() {
    float a[3][4];
    float x, y, z;
    cout << "Enter the augmented matrix (row-wise):\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            float ratio = a[j][i] / a[i][i];
            for (int k = 0; k < 4; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    z = a[2][3] / a[2][2];
    y = (a[1][3] - a[1][2] * z) / a[1][1];
    x = (a[0][3] - a[0][2] * z - a[0][1] * y) / a[0][0];

    // Output
    cout << "\nSolution:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}


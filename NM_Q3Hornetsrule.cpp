#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
 {
     //f(x) = x3 - 2x2 + 5x + 10 using X=5
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    double a[100]; // Array to store coefficients
    cout << "Enter the coefficients (from highest degree to constant term):\n";
    for (int i = degree; i >= 0; i--)
    {
        cout << "Coefficient of x^" << i << ": ";
        cin >> a[i];
    }
    double x;
    cout << "Enter the value of x: ";
    cin >> x;
    // Horner’s Rule formula: P(n) = a(n)
    double result = a[degree];

    // Loop from (n-1) down to 0
    for (int i = degree - 1; i >= 0; i--) {
        result = result * x + a[i];
    }
    cout << "\nThe value of the polynomial is: " << result << endl;
    return 0;
}


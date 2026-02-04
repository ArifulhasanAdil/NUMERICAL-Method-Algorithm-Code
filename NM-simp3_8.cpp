#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x / (1 + x * x);
}
int main() {
    double a = 0, b = 1;
    int n; // must be multiple of 3
    cout << "Enter number of subintervals (multiple of 3) n: ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "n must be a multiple of 3 for Simpson's 3/8 rule." << endl;
        return 1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 3 * f(a + i * h);
    }
    double area = (3 * h / 8) * sum;
    cout << "Approximate area under the curve = " << area << endl;

    return 0;
}


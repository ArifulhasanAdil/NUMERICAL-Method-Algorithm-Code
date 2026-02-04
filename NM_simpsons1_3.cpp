#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return exp(sin(x));
}

int main() {
    double a = 0, b = M_PI/2;
    int n;
    cout << "Enter number of subintervals (even) n: ";
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "n must be even for Simpson's 1/3 rule." << endl;
        return 1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }
    double area = (h / 3) * sum;
    cout << "Approximate area under the curve = " << area << endl;

}

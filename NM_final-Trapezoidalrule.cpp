#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 5 * log10(x);
}

int main() {
    double a, b;
    int n;
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of subintervals n: ";
    cin >> n;

    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        sum += 2 * f(a + i * h);
    }
    double area = (h / 2) * sum;
    cout << "Approximate area under the curve = " << area << endl;

}


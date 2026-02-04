#include <stdio.h>
#include<bits/stdc++.h>
int main()
{
    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {1, 8, 27, 64, 125};
    double h = x[1] - x[0]; // step size
    double x_point = 1;

    double f_prime = (y[1] - y[0]) / h;
    double f_double_prime = (y[2] - 2*y[1] + y[0]) / (h*h);

    printf("At x = %.2lf, first derivative f' = %.2lf\n", x_point, f_prime);
    printf("At x = %.2lf, second derivative f'' = %.2lf\n", x_point, f_double_prime);

    return 0;
}

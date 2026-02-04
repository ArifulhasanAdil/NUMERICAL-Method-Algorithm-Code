#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    double x[4] = {2, 4, 6, 8};
    double y[4] = {1.4, 2.0, 2.4, 2.8};

    double Sx=0, Sx2=0, Sx3=0, Sx4=0;
    double Sy=0, Sxy=0, Sx2y=0;

    // Calculate required summations
    for(int i = 0; i < n; i++) {
        Sx   += x[i];
        Sx2  += x[i] * x[i];
        Sx3  += x[i] * x[i] * x[i];
        Sx4  += x[i] * x[i] * x[i] * x[i];
        Sy   += y[i];
        Sxy  += x[i] * y[i];
        Sx2y += x[i] * x[i] * y[i];
    }

    // Solve normal equations using Cramer's Rule
    double D  = n*(Sx2*Sx4 - Sx3*Sx3)
              - Sx*(Sx*Sx4 - Sx2*Sx3)
              + Sx2*(Sx*Sx3 - Sx2*Sx2);

    double Da = Sy*(Sx2*Sx4 - Sx3*Sx3)
              - Sx*(Sxy*Sx4 - Sx3*Sx2y)
              + Sx2*(Sxy*Sx3 - Sx2*Sx2y);

    double Db = n*(Sxy*Sx4 - Sx3*Sx2y)
              - Sy*(Sx*Sx4 - Sx2*Sx3)
              + Sx2*(Sx*Sx2y - Sxy*Sx2);

    double Dc = n*(Sx2*Sx2y - Sxy*Sx3)
              - Sx*(Sx*Sx2y - Sxy*Sx2)
              + Sy*(Sx*Sx3 - Sx2*Sx2);

    double a = Da / D;
    double b = Db / D;
    double c = Dc / D;

    printf("Least Square Parabola:\n");
    printf("y = %.4f + %.4fx + %.4fx^2\n", a, b, c);


    return 0;
}

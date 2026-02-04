#include<bits/stdc++.h>
int main()
{
    float D, Dx, Dy, Dz;
    float x, y, z;

    D = 27*(15*54 - 2*1) - 6*(6*54 - 2*1) + (-1)*(6*1 - 15*1);

    Dx = 85*(15*54 - 2*1) - 6*(72*54 - 2*110) + (-1)*(72*1 - 15*110);

    Dy = 27*(72*54 - 2*110) - 85*(6*54 - 2*1) + (-1)*(6*110 - 72*1);

    Dz = 27*(15*110 - 72*1) - 6*(6*110 - 72*1) + 85*(6*1 - 15*1);

    if (D == 0)
    {
        printf("No unique solution exists.\n");
    }
    else
    {
        x = Dx / D;
        y = Dy / D;
        z = Dz / D;

        printf("Solution using Cramer's Rule:\n");
        printf("x = %.2f\n", x);
        printf("y = %.2f\n", y);
        printf("z = %.2f\n", z);
    }
    return 0;
}


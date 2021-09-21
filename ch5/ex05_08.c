// Show the value of x after each of the statement is performed

#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("fabs(10.85) is %f\n", fabs(10.85));
    printf("floor(10.85) is %f\n\n", floor(10.85));

    printf("fabs(-0.678) is %f\n", fabs(-0.678));
    printf("ceil(9.234) is %f\n\n", ceil(9.234));

    printf("fabs(0.0) i %f\n", fabs(0.0));
    printf("ceil(-34.87) is %f\n\n", ceil(-34.87));

    printf("ceil(-fabs(-12 - floor(-9.5))) is %f\n",
        ceil(-fabs(-12 - floor(-9.5))));
}
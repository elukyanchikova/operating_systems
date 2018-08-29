#include <stdio.h>
int main()
{
int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    
    printf("Size of int: %ld bits, max int value: %d \n", sizeof(i),i);
    printf("Size of float: %ld bits, max float value: %f \n", sizeof f, f);
    printf("Size of double: %ld bits, max double value: %lf \n", sizeof(d),d);
return 0;
}
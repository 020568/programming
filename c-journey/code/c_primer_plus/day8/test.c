#include<stdio.h>
int main() 
{ 
    double a;
    double b;
    scanf("%lf %lf",&a,&b);
    printf("%.6f*%.6f=%.6f\n",a,b,a*b);
    printf("%.6f/%.6f=%.6f",a,b,a/b);

    return 0; 
}
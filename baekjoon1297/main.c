#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double d,h_ratio,w_ratio;
    int h,w;
    scanf("%lf %lf %lf",&d,&h_ratio,&w_ratio);
    h=(int)sqrt((d*d*h_ratio*h_ratio)/(h_ratio*h_ratio+w_ratio*w_ratio));
    w=(int)sqrt((d*d*w_ratio*w_ratio)/(h_ratio*h_ratio+w_ratio*w_ratio));
    printf("%d %d",h,w);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
    if(a<b)
        return gcd(b,a);
    else if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int T;
    scanf("%d",&T);
    int a[T],b[T];
    for(int i=0;i<T;i++)
        scanf("%d %d",&a[i],&b[i]);
    for(int i=0;i<T;i++)
        printf("%d %d\n",a[i]*b[i]/gcd(a[i],b[i]),gcd(a[i],b[i]));
    return 0;
}

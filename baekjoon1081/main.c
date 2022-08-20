#include <stdio.h>
#include <stdlib.h>

long long pow_10(long long k)
{
    long long ret=1;
    for(int i=0;i<k;i++)
        ret*=10;
    return ret;
}

long long log_10(long long x)
{
    long long ret=0;
    while(x>=10){
        ret++;
        x/=10;
    }
    return ret;
}

long long f_onedigit(long long k)
{
    long long ret=((k+1)*k)/2;
    return ret;
}

long long f_powerof10(long long x)
{
    long long n=log_10(x), ret=45*n*pow_10(n-1)+1;
    return ret;
}

long long f_kpowerof10(long long x)
{
    long long n=log_10(x),k=x/(pow_10(n)),ret=k*f_powerof10(pow_10(n))+pow_10(n)*f_onedigit(k-1);
    return ret;
}

long long f(long long x)
{
    long long n=log_10(x),a=x/(pow_10(n)),k=x%pow_10(n);
    if(k<10)
        return f_kpowerof10(a*pow_10(n))+a*k+f_onedigit(k);
    return f_kpowerof10(a*pow_10(n))+a*k+f(k);
}

int main()
{
    long long L,U;
    scanf("%lld %lld",&L,&U);
    printf("%lld",f(U)-f(L-1));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

long long sum(long long n)
{
    long long ret=0,k=1;
    while(n>0){
        ret+=n*((k+1)/2);
        n/=2;
        k*=2;
    }
    return ret;
}

int main()
{
    long long A,B;
    scanf("%lld %lld",&A,&B);
    printf("%lld",sum(B)-sum(A-1));
    return 0;
}

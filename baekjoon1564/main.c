#include <stdio.h>
#include <stdlib.h>

long long fact_5(int n)
{
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        while(0==ans%10)ans/=10;
        ans%=1000000000000;
    }
    ans%=100000;
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%05lld",fact_5(n));
    return 0;
}

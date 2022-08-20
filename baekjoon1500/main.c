#include <stdio.h>
#include <stdlib.h>

int main()
{
    int S,K;
    unsigned long long A=1;
    scanf("%d %d",&S,&K);
    for(int i=0;i<S%K;i++)
        A*=S/K+1;
    for(int i=0;i<K-S%K;i++)
        A*=S/K;
    printf("%llu",A);
    return 0;
}

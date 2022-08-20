#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    long long int number;
    scanf("%d",&N);
    int div[N];
    scanf("%d",&div[0]);
    int min_N=div[0],max_N=div[0];
    for(int i=1;i<N;i++){
        scanf("%d",&div[i]);
        if(div[i]<min_N)
            min_N=div[i];
        if(div[i]>max_N)
            max_N=div[i];
    }
    if(N==1)
        number=div[0]*div[0];
    else
        number=min_N*max_N;
    printf("%lld",number);
    return 0;
}

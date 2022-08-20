#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, zeros[41], ones[41];
    scanf("%d",&T);
    int N[T];
    for(int i=0;i<T;i++){
        scanf("%d",&N[i]);
    }
    zeros[0]=1;
    ones[0]=0;
    zeros[1]=0;
    ones[1]=1;
    for(int i=2;i<41;i++){
        zeros[i]=zeros[i-1]+zeros[i-2];
        ones[i]=ones[i-1]+ones[i-2];
    }
    for(int i=0;i<T;i++){
        printf("%d %d\n",zeros[N[i]],ones[N[i]]);
    }
    return 0;
}

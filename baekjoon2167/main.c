#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,K;
    scanf("%d %d",&N,&M);
    int a[N*M];
    for(int i=0;i<N*M;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&K);
    int points[4*K],sum[K];
    for(int i=0;i<4*K;i++){
        scanf("%d",&points[i]);
        points[i]--;
    }
    for(int i=0;i<K;i++){
        sum[i]=0;
        for(int j=points[4*i];j<=points[4*i+2];j++){
            for(int k=points[4*i+1];k<=points[4*i+3];k++)
                sum[i]+=a[j*M+k];
        }
        printf("%d\n",sum[i]);
    }

    return 0;
}

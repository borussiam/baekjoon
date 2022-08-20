#include <stdio.h>
#include <stdlib.h>

int cache[30*30]={0};

int C(int n,int r)
{
    if(r==0||r==n)
        return 1;
    if (cache[(n-1)*30+r]!=0)
        return cache[(n-1)*30+r];
    else{
        cache[(n-1)*30+r]=C(n-1,r-1)+C(n-1,r);
        return cache[(n-1)*30+r];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int N[T],M[T],ret[T];
    for(int i=0;i<T;i++)
        scanf("%d %d",&N[i],&M[i]);
    for(int i=0;i<T;i++){
        ret[i]=C(M[i],N[i]);
        printf("%d\n",ret[i]);
    }
    return 0;
}

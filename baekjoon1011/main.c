#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    int x[T],y[T],d[T],n,ans[T];
    for(int i=0;i<T;i++){
        scanf("%d %d",&x[i],&y[i]);
        d[i]=y[i]-x[i];
    }
    for(int i=0;i<T;i++){
        n=(int)sqrt(d[i]-1);
        if(n*n+n>=d[i]){
            ans[i]=2*n;
        }
        else{
            ans[i]=2*n+1;
        }
        printf("%d\n",ans[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int a[T],b[T],remainder[T];
    for(int i=0;i<T;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(int i=0;i<T;i++){
        a[i]%=10;
        if(b[i]%4==0)
            b[i]=4;
        else
            b[i]%=4;
        remainder[i]=a[i];
        for(int j=1;j<b[i];j++){
            remainder[i]=(remainder[i]*a[i])%10;
        }
    }
    for(int i=0;i<T;i++){
        if(remainder[i]==0)
            printf("%d\n",remainder[i]+10);
        else
            printf("%d\n",remainder[i]);
    }
    return 0;
}

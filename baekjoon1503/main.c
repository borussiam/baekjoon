#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a)<(b)? a:b

int main()
{
    int N,S,A[1001]={0},n,ret=1000000000;
    scanf("%d %d",&N,&S);
    for(int i=0;i<S;i++){
        scanf("%d",&n);
        A[n]=1;
    }
    for(int i=1;i<=1001;i++){
        if(A[i])
            continue;
        for(int j=i;j<=1001;j++){
            if(A[j])
                continue;
            for(int k=j;k<=1001;k++){
                if(A[k])
                    continue;
                ret=min(ret,abs(N-i*j*k));
//Wrong Answer: Why?
/*                if(i*j*(k-1)>N)
                    break;*/
            }
        }
    }
    printf("%d",ret);
    return 0;
}

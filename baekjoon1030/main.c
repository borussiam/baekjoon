#include <stdio.h>
#include <stdlib.h>

int power(int n,int k)
{
    int ret=1;
    while(k--) ret*=n;
    return ret;
}

int main()
{
    int s,N,K,R1,R2,C1,C2;
    scanf("%d %d %d %d %d %d %d",&s,&N,&K,&R1,&R2,&C1,&C2);
    for(int i=R1;i<=R2;i++){
        for(int j=C1;j<=C2;j++){
            int flag=0;
            for(int k=0;k<s;k++){
                int r=(i/power(N,k))%N,c=(j/power(N,k))%N,low=(N-K)/2,high=(N+K)/2;
                if(low<=r&&r<high&&low<=c&&c<high){
                    flag=1;
                    break;
                }
            }
            if(flag) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}

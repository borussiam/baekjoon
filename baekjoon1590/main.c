#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,t,flag=0;
    scanf("%d %d",&n,&t);
    int S[n],I[n],N[n],W[n];
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&S[i],&I[i],&N[i]);
        int j=0;
        while(t>S[i]+j*I[i]&&j<N[i]) j++;
        if(j>=N[i]) W[i]=-1;
        else{
            W[i]=S[i]+j*I[i]-t;
            flag=1;
        }
    }
    if(flag==0){
        printf("-1");
    }
    else{
        int ans=2147483647;
        for(int i=0;i<n;i++){
            if(ans>W[i]&&W[i]!=-1) ans=W[i];
        }
        printf("%d",ans);
    }
    return 0;
}

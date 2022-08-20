#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N,K,loc[24],i=0,index=0,dif,ans=0;
    scanf("%d %d",&N,&K);
    while(N>0){
        if(N%2==1){
            loc[index]=i;
            index++;
        }
        N/=2;
        i++;
    }
    if(index<=K)
        printf("0");
    else{
        dif=index-K;
        for(i=0;i<dif+1;i++){
            ans+=(int)pow(2,loc[i]);
        }
        ans=(int)pow(2,loc[i-1]+1)-ans;
        printf("%d",ans);
    }
    return 0;
}

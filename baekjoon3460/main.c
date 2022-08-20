#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,loc[20];
    scanf("%d",&T);
    int n[T];
    for(int i=0;i<T;i++)
        scanf("%d",&n[i]);
    for(int i=0;i<T;i++){
        int k=0,index=0;
        while(n[i]>0){
            if(n[i]%2==1){
                loc[index]=k;
                index++;
            }
            n[i]/=2;
            k++;
        }
        for(int j=0;j<index;j++)
            printf("%d ",loc[j]);
        printf("\n");
    }
    return 0;
}

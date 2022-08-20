#include <stdio.h>
#include <stdlib.h>

int h[50];

double s(int i,int j)
{
    if(i<0||j<0||i>=50||j>=50) return 0;
    double slope=((double)h[i]-(double)h[j])/((double)i-(double)j);
    return slope;
}

int main()
{
    int N,ans=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&h[i]);
    for(int i=0;i<N;i++){
        int see=0;
        int min_slope=1000000001,max_slope=-1000000001;
        for(int j=i-1;j>=0;j--){
            if(s(i,j)<min_slope){
                see++;
                min_slope=s(i,j);
            }
        }
        for(int j=i+1;j<N;j++){
            if(s(i,j)>max_slope){
                see++;
                max_slope=s(i,j);
            }
        }
        if(see>ans) ans=see;
    }
    printf("%d",ans);
    return 0;
}

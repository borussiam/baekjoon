#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int ccw(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
    ll cross=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    if(cross>0) return 1;
    else if(cross<0) return -1;
    else return 0;
}

int main()
{
    int N,ans=0;
    scanf("%d",&N);
    int h[N];
    for(int i=0;i<N;i++) scanf("%d",&h[i]);
    for(int i=0;i<N;i++){
        int v=0;
        for(int j=i-1;j>=0;j--){
            int flag=0;
            for(int k=i-1;k>j;k--){
                if(ccw(i,h[i],j,h[j],k,h[k])<=0){
                    flag=1;
                    break;
                }
            }
            if(flag==0) v++;
        }
        for(int j=i+1;j<N;j++){
            int flag=0;
            for(int k=i+1;k<j;k++){
                if(ccw(i,h[i],j,h[j],k,h[k])>=0){
                    flag=1;
                    break;
                }
            }
            if(flag==0) v++;
        }
        if(v>ans) ans=v;
    }
    printf("%d",ans);
    return 0;
}

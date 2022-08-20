#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,ans;
    scanf("%d %d",&N,&M);
    int T[M],solved[N],max_solved=-1;
    for(int i=0;i<M;i++) scanf("%d",&T[i]);
    int S[N][M];
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&S[i][j]);
    for(int i=0;i<N;i++){
            solved[i]=0;
            for(int j=0;j<M;j++){
                if(S[i][j]==T[j]) solved[i]++;
            }
            if(solved[i]>max_solved){
                ans=i;
                max_solved=solved[i];
            }
    }
    printf("%d",ans+1);
    return 0;
}

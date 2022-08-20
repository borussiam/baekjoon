#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,obs[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},cross=0;
    scanf("%d",&N);
    int id[N],pos[N];
    for(int i=0;i<N;i++){
        scanf("%d %d",&id[i],&pos[i]);
        id[i]--;
    }
    for(int i=0;i<N;i++){
        if(obs[id[i]]==-1){
            obs[id[i]]=pos[i];
            continue;
        }
        else if(obs[id[i]]!=pos[i]){
            obs[id[i]]=pos[i];
            cross++;
        }
    }
    printf("%d",cross);
    return 0;
}

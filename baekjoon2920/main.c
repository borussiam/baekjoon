#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[8],ascend=1,descend=1,mix=0;
    for(int i=0;i<8;i++)
        scanf("%d",&n[i]);
    for(int i=0;i<8;i++){
        if(n[i]!=i+1){
            ascend=0;
            break;
        }
    }
    for(int i=0;i<8;i++){
        if(n[i]!=8-i){
            descend=0;
            break;
        }
    }
    if(ascend==1)
        printf("ascending");
    else if(descend==1)
        printf("descending");
    else
        printf("mixed");
    return 0;
}

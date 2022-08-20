#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[9],max=0,max_index;
    for(int i=0;i<9;i++){
        scanf("%d",&n[i]);
        if(n[i]>max){
            max=n[i];
            max_index=i+1;
        }
    }
    printf("%d\n%d",max,max_index);
    return 0;
}

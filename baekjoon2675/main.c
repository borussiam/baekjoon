#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int R[T];
    char S[T][21];
    for(int i=0;i<T;i++)
        scanf("%d %s",&R[i],S[i]);
    for(int i=0;i<T;i++){
        int j=0;
        while(S[i][j]!='\0'){
            for(int k=0;k<R[i];k++)
                printf("%c",S[i][j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}

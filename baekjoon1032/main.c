#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, k=0;
    char a[50][51], ret[51];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%s", a[i]);
    }

    while(a[0][k]!='\0'){
        int equal=0;
        for(int i=1;i<N;i++){
            if(a[0][k]!=a[i][k]){
                equal=1;
                break;
            }
        }
        if(equal==0){
            ret[k]=a[0][k];
        }
        else{
            ret[k]='?';
        }
        k++;
    }

    for(int i=0;i<k;i++){
        printf("%c", ret[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX1 101
#define MAX2 28

int main()
{
    int T;
    scanf("%d\n",&T);
    char m[T][101],encrypt[T][28];
    for(int i=0;i<T;i++){
        fgets(m[i],MAX1,stdin);
        fgets(encrypt[i],MAX2,stdin);
    }
    for(int i=0;i<T;i++){
        int j=0;
        while(m[i][j]!='\0'){
            if(65<=m[i][j]&&m[i][j]<=90){
                printf("%c",encrypt[i][m[i][j]-65]);
            }
            else
                printf(" ");
            j++;
        }
        printf("\n");
    }
    return 0;
}

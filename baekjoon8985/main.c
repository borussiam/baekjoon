#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    char a[T][81];
    int point[T];
    for(int i=0;i<T;i++){
        scanf("%s", a[i]);
    }
    for(int i=0;i<T;i++){
        int j=0, count=1;
        point[i]=0;
        while(a[i][j]!='\0'){
            if(a[i][j]=='O'){
                point[i]+=count;
                count++;
            }
            else{
                count=1;
            }
            j++;
        }
    }
    for(int i=0;i<T;i++){
        printf("%d\n", point[i]);
    }
    return 0;
}

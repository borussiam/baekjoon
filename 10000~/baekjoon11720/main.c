#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum=0;
    char c;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%c",&c);
        sum+=c-48;
    }
    printf("%d",sum);
    return 0;
}

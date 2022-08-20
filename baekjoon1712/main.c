#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,x;
    scanf("%d %d %d",&A,&B,&C);
    if(B>=C)
        x=-1;
    else
        x=A/(C-B)+1;
    printf("%d",x);
    return 0;
}

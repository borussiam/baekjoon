#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,F,q,r;
    scanf("%d%d",&N,&F);
    q=(N/100)*100;
    r=q%F;
    if(r==0)
        printf("00");
    else
        printf("%02d",F-r);
    return 0;
}

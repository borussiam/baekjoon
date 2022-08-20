#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,A,B,round=1;
    scanf("%d %d %d",&N,&A,&B);
    while(!(A%2==1&&B-A==1)&&!(B%2==1&&A-B==1)){
        A=(A+1)/2;
        B=(B+1)/2;
        N=(N+1)/2;
        round++;
    }
    printf("%d",round);
    return 0;
}

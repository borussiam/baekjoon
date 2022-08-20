#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,x3,y1,y2,y3;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    int cross=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    if(cross>0) printf("1");
    else if(cross==0) printf("0");
    else if(cross<0) printf("-1");
    return 0;
}

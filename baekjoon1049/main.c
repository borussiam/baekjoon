#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,price;
    scanf("%d %d",&N,&M);
    int six[M],one[M];
    scanf("%d %d",&six[0],&one[0]);
    int six_min=six[0],one_min=one[0];
    for(int i=1;i<M;i++){
        scanf("%d %d",&six[i],&one[i]);
        if(six[i]<six_min)
            six_min=six[i];
        if(one[i]<one_min)
            one_min=one[i];
    }
    if(one_min*6<six_min)
        price=one_min*N;
    else if(six_min<one_min*(N%6))
        price=six_min*(N/6+1);
    else
        price=six_min*(N/6)+one_min*(N%6);
    printf("%d",price);
    return 0;
}

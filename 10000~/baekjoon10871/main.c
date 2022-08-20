#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X, N, A[10000], B[10000], count=0;
    scanf("%d %d", &N, &X);
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    for(int i=0;i<N;i++){
        if(A[i]<X){
            B[count]=A[i];
            count++;
        }
    }
    for(int i=0;i<count;i++){
        printf("%d ", B[i]);
    }
    return 0;
}

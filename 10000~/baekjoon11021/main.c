#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    int A[T], B[T];
    for(int i=0;i<T;i++){
        scanf("%d %d", &A[i], &B[i]);
    }
    for(int i=0;i<T;i++){
        printf("Case #%d: %d\n", i+1 ,A[i]+B[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
    int n1=*(int *)a;
    int n2=*(int *)b;
    if(n1>n2)
        return 1;
    else if(n1<n2)
        return -1;
    return 0;
}

int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    qsort(A,N,sizeof(int),compare);
    for(int i=0;i<N;i++)
        printf("%d\n",A[i]);
    return 0;
}

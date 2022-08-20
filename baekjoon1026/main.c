#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int*list, int n)
{
    int key,i,j;

    for(i=0;i<n;i++){
        key=list[i];
        for(j=i-1;j>=0&&list[j]>key;j--)
            list[j+1]=list[j];
        list[j+1]=key;
    }
}



int main()
{
    int N,ans=0;
    scanf("%d",&N);
    int A[N],B[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&B[i]);
    insertion_sort(A,N);
    insertion_sort(B,N);
    for(int i=0;i<N;i++)
        ans+=A[i]*B[N-i-1];
    printf("%d",ans);
    return 0;
}

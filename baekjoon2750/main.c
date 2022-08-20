#include <stdio.h>
#include <stdlib.h>

void insertionSort(int*a,int size)
{
    int i,j,key;
    for(i=1;i<size;i++){
        key=a[i];
        j=i-1;
        while(j>=0&&key<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    insertionSort(A,N);
    for(int i=0;i<N;i++)
        printf("%d\n",A[i]);
    return 0;
}

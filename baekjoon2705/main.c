#include <stdio.h>
#include <stdlib.h>

int memo_recursively_palindromic_partitions[1001]={1,1,2,};

int recursively_palindromic_partitions(int n)
{
    int ret=0;
    if(memo_recursively_palindromic_partitions[n]!=0)
        ret=memo_recursively_palindromic_partitions[n];
    else{
        for(int i=0;i<=n/2;i++)
            ret+=recursively_palindromic_partitions(i);
        memo_recursively_palindromic_partitions[n]=ret;
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    int N[T];
    for(int i=0;i<T;i++)
        scanf("%d",&N[i]);
    for(int i=0;i<T;i++)
        printf("%d\n",recursively_palindromic_partitions(N[i]));
    return 0;
}

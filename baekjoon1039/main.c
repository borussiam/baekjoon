#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* a, int l)
{
    for(int i=1;i<l;i++){
        int temp=a[i],j=i-1;
        while(temp>a[j]){
            if(j<0) break;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int same_num(int* a,int l)
{
    int flag=0;
    for(int i=1;i<l;i++){
        if(a[i]==a[i-1]){
            flag=1;
            break;
        }
    }
    return flag;
}

int main()
{
    int N,M=0,K;
    scanf("%d %d",&N,&K);
    int a=N;
    while(a>0){
        a/=10;
        M++;
    }
    int n[M],s[M],change[3][K];
    a=N;
    for(int i=1;i<=M;i++){
        n[M-i]=a%10;
        s[M-i]=n[M-i];
        a/=10;
    }
    selection_sort(s,M);
    if(N<=10||(N<100&&N%10==0)) printf("-1");
    else{
        int i=0,j=0,k,temp;
        while(i<K){
            if(j>=M){
                if(!same_num(s,M)&&(K-i)%2){
                    temp=n[M-2];
                    n[M-2]=n[M-1];
                    n[M-1]=temp;
                }
                break;
            }
            if(n[j]!=s[j]){
                for(k=M-1;k>=0;k--)
                    if(n[k]==s[j]) break;
                temp=n[j];
                n[j]=n[k];
                n[k]=temp;
                change[0][i]=n[j];
                change[1][i]=n[k];
                change[2][i]=k;
                for(int c=0;c<i;c++){
                    if(change[0][c]==change[0][i]&&change[1][c]>change[1][i]){
                        temp=change[1][c];
                        change[1][c]=change[1][i];
                        change[1][i]=temp;
                        n[change[2][i]]=change[1][i];
                        n[change[2][c]]=change[1][c];
                    }
                }
                i++;
            }
            j++;
        }
        for(int k=0;k<M;k++) printf("%d",n[k]);
    }
    return 0;
}

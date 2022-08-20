#include <iostream>

using namespace std;

int **memo,**p;
int f(int n, int k)
{
    if(memo[n][k]!=0) return memo[n][k];
    if(n==0){
        memo[0][0]=p[0][0];
        memo[0][1]=p[0][1];
        memo[0][2]=p[0][2];
        return memo[n][k];
    }
    if(k==0){
        memo[n][0]=p[n][0]+min(f(n-1,1),f(n-1,2));
    }
    if(k==1){
        memo[n][1]=p[n][1]+min(f(n-1,2),f(n-1,0));
    }
    if(k==2){
        memo[n][2]=p[n][2]+min(f(n-1,0),f(n-1,1));
    }
    return memo[n][k];
}

int g(int n)
{
    n--;
    int ret=min(min(f(n,0),f(n,1)),f(n,2));
    return ret;
}

int main()
{
    int N;
    cin >> N;
    memo=(int**)malloc(N*sizeof(int*));
    p=(int**)malloc(N*sizeof(int*));
    for(int i=0;i<N;i++){
        memo[i]=(int*)calloc(3,sizeof(int));
        p[i]=(int*)malloc(3*sizeof(int));
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    cout << g(N) << endl;
    return 0;
}

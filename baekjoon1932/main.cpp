#include <iostream>
#include <cstring>

using namespace std;

int memo[500][500],p[500][500];

int f(int n,int k)
{
    if(n==0) return p[0][0];
    int& ret=memo[n][k];
    if(ret!=-1) return ret;
    if(k==0) ret=f(n-1,0)+p[n][0];
    else if(k==n) ret=f(n-1,n-1)+p[n][n];
    else ret=max(f(n-1,k-1),f(n-1,k))+p[n][k];
    return ret;
}

int g(int n)
{
    int ret=0;
    for(int i=0;i<n;i++) ret=max(ret,f(n-1,i));
    return ret;
}

int main()
{
    memset(memo,-1,sizeof(memo));
    int n;
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<=i;j++) cin >> p[i][j];
    cout << g(n) << endl;
    return 0;
}

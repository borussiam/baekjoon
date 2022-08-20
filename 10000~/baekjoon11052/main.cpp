#include <iostream>
#include <cstring>

using namespace std;

int dp[1005][1005],p[1005];

int max3(int a,int b,int c)
{
    return (a>=b&&a>=c) ? a : b>=c ? b : c;
}

int f(int n,int k)
{
    if(n==0) return 0;
    if(k==1) return n*p[1];
    if(n<k) return f(n,n);
    if(dp[n][k]!=-1) return dp[n][k];
    int& ret=dp[n][k];
    ret=max3(ret,f(n-k,k)+p[k],f(n,k-1));
    return ret;
}

int main()
{
    for(int i=0;i<1005;i++) memset(dp[i],-1,sizeof(dp[i]));
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i];
    cout << f(n,n) << endl;
    return 0;
}

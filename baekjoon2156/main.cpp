#include <iostream>
#include <cstring>

using namespace std;

int n,v[10005],dp[10005];

int wine(int now)
{
    if(now<1) return 0;
    if(dp[now]!=-1) return dp[now];
    int& ret=dp[now];
    return ret=max(max(wine(now-3),wine(now-4))+v[now-1],wine(now-2))+v[now];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    dp[1]=v[1];
    dp[2]=v[1]+v[2];
    dp[3]=max(v[1],v[2])+v[3];
    wine(n);
    wine(n-1);
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,dp[i]);
    }
    cout << mx << endl;
    return 0;
}

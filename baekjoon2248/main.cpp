#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,L,l,dp[32][32],result[32];
ll binary(int n,int left)
{
    ll &ret=dp[n][left];
    if(ret!=-1) return ret;
    if(n==0||left==0) return ret=1;
    return ret=binary(n-1,left)+binary(n-1,left-1);
}
void skip(int n,int left,int k)
{
    int curr=N-n;
    if(n==0) return;
    if(left==0){
        for(int i=0;i<n;i++)
            result[curr+i]=0;
        return;
    }
    ll pivot=binary(n-1,left);
    if(k<pivot){
        result[curr]=0;
        skip(n-1,left,k);
    }
    else{
        result[curr]=1;
        skip(n-1,left-1,k-pivot);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    cin >> N >> L >> l;
    skip(N,L,l-1);
    for(int i=0;i<N;i++) cout << result[i];
    cout << '\n';
    return 0;
}

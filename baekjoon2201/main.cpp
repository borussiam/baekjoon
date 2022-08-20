#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[87],K,N=2;
void skip(ll left,ll k)
{
    if(left<=0) return;
    if(k<0) return;
    ll pivot=dp[left-1];
    if(k<pivot){
        cout << 0;
        skip(left-1,k);
    }
    else{
        cout << 1;
        skip(left-1,k-pivot);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    dp[0]=1; dp[1]=2; dp[2]=3;
    while(1){
        dp[N]=dp[N-1]+dp[N-2];
        if(dp[N]>K) break;
        N++;
    }
    cout << 1; if(K==1) return 0;
    cout << 0; if(K==2) return 0;
    skip(N-2,K-dp[N-1]);
    cout << '\n';
    return 0;
}

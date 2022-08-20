#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n;
    int a[2*n+1]={0},dp[2*n+1]={0},r=0,p=0;
    for(int i=1;i<=n;i++) cin >> a[2*i-1];
    for(int i=1;i<2*n;i++){
        if(i<r) dp[i]=min(dp[2*p-i],r-i);
        else dp[i]=0;
        while(i-dp[i]-1>=0&&i+dp[i]+1<=2*n&&a[i-dp[i]-1]==a[i+dp[i]+1])
            dp[i]++;
        if(i+dp[i]>r){
            r=i+dp[i];
            p=i;
        }
    }
    cin >> m;
    while(m--){
        int s,e;
        cin >> s >> e;
        cout << (dp[s+e-1]>e-s) << "\n";
    }
    return 0;
}

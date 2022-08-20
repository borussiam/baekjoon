#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000000;
int memo[205][205];

int ways(int n,int k)
{
    if(n==0||k==1) return 1;
    if(k==2) return n+1;
    int& ret=memo[n][k];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<=n;i++){
        ret=(ret+ways(i,k-1))%MOD;
    }
    return ret;
}

int main()
{
    memset(memo,-1,sizeof(memo));
    int n,k;
    cin >> n >> k;
    cout << ways(n,k) << endl;
    return 0;
}

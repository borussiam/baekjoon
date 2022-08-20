#include <bits/stdc++.h>

using namespace std;

int n,m,memo[1005][1005],a[1005][1005];

int f(int r,int c)
{
    int& ret=memo[r][c];
    if(ret!=-1) return ret;
    if(r==n||c==m){
        ret=0;
        while(r!=n){
            ret+=a[r][m];
            r++;
        }
        while(c!=m){
            ret+=a[n][c];
            c++;
        }
        return ret;
    }
    return ret=max(f(r+1,c),f(r,c+1))+a[r][c];
}

int main()
{
    for(int i=0;i<1005;i++) memset(memo[i],-1,sizeof(memo[i]));
    cin >> n >> m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    cout << f(1,1)+a[n][m] << endl;
    return 0;
}

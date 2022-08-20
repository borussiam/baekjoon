#include <bits/stdc++.h>

using namespace std;

int n,h[500][500],memo[500][500];

int days(int r,int c)
{
    int& ret=memo[r][c];
    if(ret!=-1) return ret;
    ret=1;
    if(r>0&&h[r][c]<h[r-1][c]){
        ret=max(ret,days(r-1,c)+1);
    }
    if(c>0&&h[r][c]<h[r][c-1]){
        ret=max(ret,days(r,c-1)+1);
    }
    if(r<n-1&&h[r][c]<h[r+1][c]){
        ret=max(ret,days(r+1,c)+1);
    }
    if(c<n-1&&h[r][c]<h[r][c+1]){
        ret=max(ret,days(r,c+1)+1);
    }
    return ret;
}

int main()
{
    memset(memo,-1,sizeof(memo));
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> h[i][j];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,days(i,j));
        }
    }
    cout << ans << endl;
    return 0;
}

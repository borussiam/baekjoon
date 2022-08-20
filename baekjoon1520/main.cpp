#include <bits/stdc++.h>

using namespace std;

int N,M,h[500][500],memo[500][500];

int ways(int r,int c)
{
    int& ret=memo[r][c];
    if(ret!=-1) return ret;
    if(r==N-1&&c==M-1) return 1;
    ret=0;
    if(r>0&&h[r][c]>h[r-1][c])
        ret+=ways(r-1,c);
    if(c>0&&h[r][c]>h[r][c-1])
        ret+=ways(r,c-1);
    if(r<N-1&&h[r][c]>h[r+1][c])
        ret+=ways(r+1,c);
    if(c<M-1&&h[r][c]>h[r][c+1])
        ret+=ways(r,c+1);
    return ret;
}

int main()
{
    memset(memo,-1,sizeof(memo));
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> h[i][j];
    int ans=ways(0,0);
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int dr[4]={-1,0,0,1},dc[4]={0,-1,1,0};
int c,r,a[52][52];

void f(int r,int c)
{
    a[r][c]=0;
    for(int i=0;i<4;i++){
        if(a[r+dr[i]][c+dc[i]]==1)
            f(r+dr[i],c+dc[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int k,ans=0;
        cin >> c >> r >> k;
        for(int i=0;i<k;i++){
            int x,y;
            cin >> x >> y;
            a[y+1][x+1]=1;
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(a[i][j]==1){
                    f(i,j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

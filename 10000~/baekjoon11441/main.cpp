#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n;
    int sum[n+1]={0};
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        sum[i]=a+sum[i-1];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        cout << sum[y]-sum[x-1] << '\n';
    }
    return 0;
}

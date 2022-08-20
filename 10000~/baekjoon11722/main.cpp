#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int main()
{
    int n,a[1005]={0},d[1005]={0},ans=0;
    for(int i=1;i<1005;i++) d[i]=INF;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[n-i];
    for(int i=1;i<=n;i++){
        int indx=lower_bound(d,d+i,a[i])-d;
        d[indx]=a[i];
    }
    while(d[ans]!=INF) ans++;
    cout << ans-1 << endl;
    return 0;
}

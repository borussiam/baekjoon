#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a[1005]={0},d[1005]={0},ans=0;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)
            if(d[i]<d[j]+a[i]&&a[i]>a[j])
                d[i]=d[j]+a[i];
        ans=max(ans,d[i]);
    }
    cout << ans << endl;
    return 0;
}

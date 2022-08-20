#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int d[n],a[k+1]={0};
    for(int i=0;i<n;i++) cin >> d[i];
    sort(d,d+n);
    for(int i=1;i<=k;i++){
        a[i]=INF;
        for(int j=0;j<n;j++){
            if(i-d[j]>=0)
                a[i]=min(a[i],a[i-d[j]]+1);
        }
    }
    if(a[k]==INF){
        cout << -1;
        return 0;
    }
    cout << a[k] << endl;
    return 0;
}

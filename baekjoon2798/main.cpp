#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ans=0; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(m >= a[i]+a[j]+a[k] && a[i]+a[j]+a[k] > ans){
                    ans = a[i]+a[j]+a[k];
                }
            }
        }
    }
    cout << ans << '\n';        
    return 0;
}

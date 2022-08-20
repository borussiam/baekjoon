#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int w[2*n];
    for(int i = 0; i < 2*n; i++) cin >> w[i];
    sort(w, w+2*n);
    int ans = 1e8;
    for(int i = 0; i < n; i++){
        int tmp = w[i]+w[2*n-i-1];
        if(tmp < ans) ans = tmp;
    }
    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d[1005], dp[1005];
vector<int> parent[1005];

int build(int n)
{
    int &ret = dp[n], k = parent[n].size(), add = 0;
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < k; i++){
        add = max(add, build(parent[n][i]));
    }
    ret += d[n] + add;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        for(int i = 0; i < 1005; i++){
            if(!parent[i].empty())
                parent[i].clear();
        }
        memset(dp, -1, sizeof(dp));
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> d[i];
        for(int i = 0, x, y; i < k; i++){
            cin >> x >> y;
            parent[y].push_back(x);
        }
        int w; cin >> w;
        int ans = build(w);
        cout << ans << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void cycle(int s, int e, int* p, bool* c)
{
    c[s] = true;
    if(s == e){
        return;
    }
    cycle(p[s], e, p, c);
}

void dfs(int curr, int* g, int* p, bool* v, bool* f, bool* c)
{
    v[curr] = true;
    int next = g[curr];
    if(!v[next]){
        p[next] = curr;
        dfs(next, g, p, v, f, c);
    }
    else if(!f[next]){
        cycle(curr, next, p, c);
    }
    f[curr] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int g[n], par[n];
        bool vis[n], fin[n], cyc[n];
        fill(vis, vis+n, false);
        fill(fin, fin+n, false);
        fill(cyc, cyc+n, false);
        for(int i = 0, v; i < n; i++){
            cin >> v;
            g[i] = v-1;
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, g, par, vis, fin, cyc);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!cyc[i]){
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

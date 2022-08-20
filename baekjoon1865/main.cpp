#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--){
        int n, m, w; cin >> n >> m >> w;
        vector<pii> g[n];
        // vector<int> r[n];
        for(int i = 0, s, e, t; i < m; i++){
            cin >> s >> e >> t;
            g[s-1].push_back({e-1, t});
            g[e-1].push_back({s-1, t});
            // r[s-1].push_back(e-1);
            // r[e-1].push_back(s-1);
        }
        for(int i = 0, s, e, t; i < w; i++){
            cin >> s >> e >> t;
            g[s-1].push_back({e-1, -t});
            // r[e-1].push_back(s-1);
        }
        // bool visited[n]={0};
        // visited[0] = true;
        // queue<int> bfs;
        // bfs.push(0);
        // while(!bfs.empty()){
        //     int curr = bfs.front();
        //     bfs.pop();
        //     for(int next : r[curr]){
        //         if(!visited[next]){
        //             bfs.push(next);
        //             visited[next] = true;
        //         }
        //     }
        // }
        ll dist[n];
        fill(dist, dist+n, INF);
        bool cycle=false, visited[n]={0};
        for(int k = 0; k < n; k++){
            if(!visited[k]){
                dist[k] = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        for(auto &p : g[j]){
                            int next = p.first;
                            ll d = p.second;
                            if(dist[j]==INF){
                                continue;
                            }
                            visited[next] = true;
                            if(dist[j]!=INF && dist[next] > dist[j]+d){
                                dist[next] = dist[j]+d;
                                if(i==n-1){
                                    cycle = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(cycle){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}

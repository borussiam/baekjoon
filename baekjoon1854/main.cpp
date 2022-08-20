#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define fi first
#define se second
#define pb push_back

const ll MAX = 1005, MAX_K = 101, INF = 1e9;
int N, M, K, dist[MAX][MAX_K], vis[MAX], done = 0;
vector<pi> adj[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    fill(dist[0], dist[MAX-1]+MAX_K, INF);
    pq.push({0, 1});
    while(!pq.empty()){
        pi c = pq.top();
        pq.pop();
        int curr = c.se, dis = c.fi;
        if(vis[curr] >= K) continue;
        int cnt = vis[curr];
        // if(cnt > 0 && dis == dist[curr][cnt-1]) continue;
        if(++vis[curr] == K) ++done;
        dist[curr][cnt] = dis;
        if(done == N) break;
        for(auto &p : adj[curr]){
            int next = p.fi, d = p.se;
            pq.push({dist[curr][cnt] + d, next});
        }
    }
    for(int i = 1; i <= N; i++){
        if(dist[i][K-1] == INF) cout << "-1\n";
        else cout << dist[i][K-1] << '\n';
    }
    return 0;

}

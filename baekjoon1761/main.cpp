#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 4e4;
int N, M;
vector<pii> adj[MAX];
int parent[MAX][17], depth[MAX], dist[MAX];

void build_tree(int curr, int dis)
{
    for(pii &p : adj[curr]){
        int next = p.first, d = p.second;
        if(depth[next] == -1){
            depth[next] = depth[curr] + 1;
            parent[next][0] = curr;
            dist[next] = dis + d;
            // cout << dist[next] << ' ' << next << '\n';
            build_tree(next, dist[next]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0, u, v, w; i < N-1; i++){
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(parent, -1, sizeof(parent));
    fill(depth, depth+N, -1);
    depth[0] = 0;
    build_tree(0, 0);
    // for(int i = 0; i < N; i++){
    //     cout << dist[i] << ' ';
    // }
    // cout << "\n\n";
    for(int j = 0; j <= 15; j++){
        for(int i = 0; i < N; i++){
            if(parent[i][j] != -1){
                parent[i][j+1] = parent[parent[i][j]][j];
            }
        }
    }
    cin >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        --u; --v;
        int dist_u = dist[u], dist_v = dist[v];
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for(int j = 0; diff; j++){
            if(diff % 2){
                u = parent[u][j];
            }
            diff /= 2;
        }
        if(u != v){
            for(int j = 16; j >= 0; j--){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        int ans = dist_u + dist_v;
        if(u != -1){
            ans -= 2*dist[u];
        }
        cout << ans << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 5e4, INF = 1e8;
int N, M, parent[MAX][16], depth[MAX];
vector<int> adj[MAX];

void build_tree(int curr)
{
    for(int next : adj[curr]){
        if(depth[next] == -1){
            depth[next] = depth[curr] + 1;
            parent[next][0] = curr;
            build_tree(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0, u, v; i < N-1; i++){
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    fill(depth, depth+N, -1);
    depth[0] = 0;
    build_tree(0);
    for(int j = 0; j < 15; j++){
        for(int i = 1; i < N; i++){
            if(parent[i][j] != -1){
                parent[i][j+1] = parent[parent[i][j]][j];
            }
        }
    }
    cin >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        --u; --v;
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
            for(int j = 15; j >= 0; j--){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        cout << u + 1 << '\n';
    }
    return 0;
}

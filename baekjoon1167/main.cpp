#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100000;
vector<pii> g[MAX];
bool visited[MAX];
int max_dist, vertex;

void dfs(int node, int dist)
{
    visited[node] = true;
    for(auto p : g[node]){
        if(!visited[p.first]){
            if(dist+p.second > max_dist){
                max_dist = dist+p.second;
                vertex = p.first;
            }
            dfs(p.first, dist+p.second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V; cin >> V;
    for(int i = 0, u, v, d; i < V; i++){
        cin >> u >> v;
        --u; --v;
        do{
            cin >> d;
            g[u].push_back({v, d});
            g[v].push_back({u, d});
            cin >> v; --v;
        }while(v>=0);
    }
    dfs(0, 0);
    int start = vertex;
    max_dist = 0;
    fill(visited, visited+MAX, false);
    dfs(start, 0);
    cout << max_dist << '\n';
    return 0;
}

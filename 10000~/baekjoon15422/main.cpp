#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
typedef pair<pii, int> piii;
const int MAX_V = 50000;
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, f, s, t;
    vector<pii> g[MAX_V];
    cin >> n >>  m >> f >> s >> t;
    for(int i = 0, j, k, c; i < m; i++){
        cin >> j >> k >> c;
        g[j].push_back({k, c});
        g[k].push_back({j, c});
    }
    for(int i = 0, u, v; i < f; i++){
        cin >> u >> v;
        g[u].push_back({v, 0});
    }
    ll cents[2][50000];
    fill(cents[0], cents[0]+MAX_V, INF);
    fill(cents[1], cents[1]+MAX_V, INF);
    priority_queue<piii, vector<piii>, greater<piii> > pq;
    bool visited[2][MAX_V] = {0};
    cents[0][s] = 0;
    pq.push({{cents[0][s], s}, 0});
    while(!pq.empty()){
        int curr;
        bool used;
        do{
            curr = pq.top().first.second;
            used = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[used][curr]);
        if(visited[used][curr]){
            break;
        }
        visited[used][curr] = true;
        for(auto p : g[curr]){
            int next = p.first, c = p.second;
            if(c==0){
                if(used){
                    continue;
                }
                cents[1][next] = cents[0][curr];
                pq.push({{cents[1][next], next}, 1});
            }
            else{
                if(cents[used][next] > cents[used][curr] + c){
                    cents[used][next] = cents[used][curr] + c;
                    pq.push({{cents[used][next], next}, used});
                }
            }
        }
    }
    cout << min(cents[0][t], cents[1][t]) << '\n';
    return 0;
}

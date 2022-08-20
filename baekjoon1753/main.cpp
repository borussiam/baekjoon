#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1234567890;
const int MAX_V = 20000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E, K;
    vector<pii> g[MAX_V];
    cin >> V >> E >> K;
    --K;
    for(int i = 0, u, v, w; i < E; i++){
        cin >> u >> v >> w;
        g[u-1].push_back({v-1, w});
    }
    int dist[MAX_V];
    fill(dist, dist+MAX_V, INF);
    bool visited[MAX_V] = {0};
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[K] = 0;
    pq.push({0,K});
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[curr]);
        if(visited[curr]){
            break;
        }
        visited[curr] = true;
        for(auto p : g[curr]){
            int next = p.first, d = p.second;
            if(dist[next] > d+dist[curr]){
                dist[next] = d+dist[curr];
                pq.push({dist[next], next});
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }
        else{
            cout << dist[i] << '\n';
        }
    }
    return 0;
}

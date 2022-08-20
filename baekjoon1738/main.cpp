#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pii> g[n];
    vector<int> r[n], cycle;
    pii dist[n];
    for(int i = 0; i < n; i++){
        dist[i].first = -INF;
    }
    dist[0] = {0, -1};
    for(int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        g[u-1].push_back({v-1, w});
        r[v-1].push_back(u-1);
    }
    bool visited[n]={0};
    visited[n-1] = true;
    queue<int> bfs;
    bfs.push(n-1);
    while(!bfs.empty()){
        int curr = bfs.front();
        bfs.pop();
        for(int next : r[curr]){
            if(!visited[next]){
                bfs.push(next);
                visited[next] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(auto &p : g[j]){
                int next = p.first, d = p.second;
                if(dist[j].first==-INF){
                    break;
                }
                else if(dist[next].first < dist[j].first+d){
                    dist[next].first = dist[j].first+d;
                    dist[next].second = j;
                    if(i==n-1){
                        cycle.push_back(next);
                    }
                }
            }
        }
    }
    for(int cy : cycle){
        if(visited[cy]){
            cout << -1 << '\n';
            return 0;
        }
    }
    if(dist[n-1].first==-INF){
        cout << -1 << '\n';
        return 0;
    }
    stack<int> st;
    int k = n-1;
    while(k!=-1){
        st.push(k);
        k = dist[k].second;
    }
    while(!st.empty()){
        cout << st.top()+1 << ' ';
        st.pop();
    }
    cout << '\n';
    return 0;
}

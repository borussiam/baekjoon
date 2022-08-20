#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5+1;
vector<pii> g[2*MAX];
deque<pii> bfs;
bool visited[2*MAX]={0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    g[0].push_back({1, 1});
    g[2*MAX-1].push_back({2*MAX-2, 1});
    for(int i = 1; i < 2*MAX-1; i++){
        g[i].push_back({i-1, 1});
        g[i].push_back({i+1, 1});
        if(i < MAX){
            g[i].push_back({2*i, 0});
        }
    }
    int N, K, ans; cin >> N >> K;
    bfs.push_back({N, 0});
    visited[N] = true;
    bool found = false;
    while(!bfs.empty()){
        int curr = bfs.front().first, d = bfs.front().second;
        bfs.pop_front();
        visited[curr] = true;
        if(curr==K){
            found = true;
            ans = d;
            break;
        }
        for(auto &p : g[curr]){
            if(visited[p.first]){
                continue;
            }
            if(p.second==0){
                bfs.push_front({p.first, d});
            }
            else{
                bfs.push_back({p.first, d+1});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5;
bool cycle[MAX], visited[MAX], finished[MAX];
int g[MAX], team[MAX], parent[MAX];

void check_cycle(int s, int e)
{
    cycle[s] = true;
    if(s == e){
        return;
    }
    check_cycle(parent[s], e);
}

void dfs(int n)
{
    visited[n] = true;
    int next = g[n];
    if(!visited[next]){
        parent[next] = n;
        dfs(next);
    }
    else if(!finished[next]){
        check_cycle(n, next);
    }
    finished[n] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        fill(visited, visited+n, false);
        fill(team, team+n, -1);
        fill(cycle, cycle+n, false);
        fill(finished, finished+n, false);
        for(int i = 0, v; i < n; i++){
            cin >> v;
            g[i] = v-1;
        }
        for(int i = 0; i < n; i++){
            if(finished[i]){
                continue;
            }
            dfs(i);
        }
        // for(int i = 0; i < n; i++) printf("%d ", visited[i]);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!cycle[i]){
                // cout << i << ' ';
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

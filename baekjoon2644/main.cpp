#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a, b, m, visited[101];
vector<int> v[101];

int dfs(int node)
{
    visited[node] = 1;
    int ret = 0;
    bool found = false;
    for(int k : v[node]){
        if(k == b){
            found = true;
            break;
        }
        if(!visited[k]){
            ret += dfs(k);
        }
    }
    if(found) return 1;
    if(ret) return ret+1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b >> m;
    for(int i = 0,k,l; i < m; i++){
        cin >> k >> l;
        v[k].push_back(l);
        v[l].push_back(k);
    }
    int chon = dfs(a);
    if(chon == 0){
        cout << -1 << '\n';
    }
    else{
        cout << chon << '\n';
    }
    return 0;
}

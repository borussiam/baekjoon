#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

const int MAX = 50;
int N, M, k, ans = 0;
int t[MAX], n[MAX], p[MAX][MAX];
bool truth[MAX], chk[MAX+1];
vector<int> v[MAX+1];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> k;
    for(int i = 0; i < k; i++){
        cin >> t[i];
        q.push(t[i]);
    }
    for(int i = 0; i < M; i++){
        cin >> n[i];
        for(int j = 0; j < n[i]; j++){
            cin >> p[i][j];
            v[p[i][j]].pb(i);
        }
    }
    if(k == 0){
        cout << M << '\n';
        return 0;
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int a : v[curr]){
            truth[a] = true;
            for(int i = 0; i < n[a]; i++){
                if(chk[p[a][i]]) continue;
                chk[p[a][i]] = true;
                q.push(p[a][i]);
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(!truth[i]) ++ans;
    }
    cout << ans << '\n';
    return 0;
}

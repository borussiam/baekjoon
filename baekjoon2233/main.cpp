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

const int MAX = 2000;
int N, X, Y, cnt = 0, idx = 0, del, ans1 = -1, ans2 = -1;
int ch[MAX][2], par[MAX], depth[MAX], match[MAX*2];
bool vis[MAX];
string s;

void number(int curr)
{
    match[idx] = curr;
    while(s[++idx] != '1'){
        if(ch[curr][0] == 0) ch[curr][0] = ++cnt;
        else ch[curr][1] = ++cnt;
        par[cnt] = curr;
        depth[cnt] = depth[curr] + 1;
        number(cnt);
    }
    match[idx] = curr;
}

int find(int n1, int n2)
{
    if(n1 == -1 || n2 == -1) return 0;
    if(n1 == n2) return n1;
    int ret = 0;
    if(depth[n1] > depth[n2]){
        ret = find(par[n1], n2);
    }
    else if(depth[n1] < depth[n2]){
        ret = find(n1, par[n2]);
    }
    else ret = find(par[n1], par[n2]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(par, -1, sizeof(par));
    cin >> N >> s >> X >> Y;
    --X; --Y;
    number(0);
    del = find(match[X], match[Y]);
    for(int i = 0; i < 2*N; i++){
        if(match[i] == del){
            if(ans1 == -1) ans1 = i+1;
            else ans2 = i+1;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}

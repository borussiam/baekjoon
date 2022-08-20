#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    pii d[N], c[N];
    int good[N]; fill(good, good+N, 0);
    for(int i = 0, D, C; i < N; i++){
        cin >> D >> C;
        d[i] = {{D, C}, i};
        c[i] = {{C, D}, i};
    }
    sort(d, d+N);
    sort(c, c+N);
    int min_c = 1e5, min_d = 1e5;
    for(int i = 0; i < N; i++){
        if(d[i].fi.se < min_c){
            ++good[d[i].se];
            min_c = d[i].fi.se;
        }
    }
    for(int i = 0; i < N; i++){
        if(c[i].fi.se < min_d){
            ++good[c[i].se];
            min_d = c[i].fi.se;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(good[i] == 2){
            ++ans;
            // cout << i << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}

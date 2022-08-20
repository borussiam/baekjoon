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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;
    int wa[n][m], ac[n], time[n];
    pii result[n];
    for(int i = 0; i < n; i++) fill(wa[i], wa[i]+m, 0);
    for(int i = 0; i < n; i++){
        result[i].fi = 0;
        result[i].se.fi = 0;
        result[i].se.se = i+1;
    }
    while(q--){
        int t, team, prob;
        string r;
        cin >> t >> team >> prob >> r;
        --team; --prob;
        if(wa[team][prob] == -1) continue;
        if(r == "AC"){
            --result[team].fi;
            result[team].se.fi += t + 20*wa[team][prob];
            wa[team][prob] = -1;
        }
        else{
            ++wa[team][prob];
        }
    }
    sort(result, result+n);
    for(int i = 0; i < n; i++){
        cout << result[i].se.se << ' ' << -result[i].fi << ' ' << result[i].se.fi << '\n';
    }
    return 0;
}

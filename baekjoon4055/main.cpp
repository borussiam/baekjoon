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

pi party[105];

int best(int t, int np)
{
    int idx = -1;
    int end = 33;
    for(int i = 0; i < np; i++){
        if(party[i].fi <= t && t < party[i].se && end > party[i].se){
            end = party[i].se;
            idx = i;
        }
    }
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 1;
    int p; cin >> p;
    while(p != 0){
        for(int i = 0; i < p; i++){
            cin >> party[i].fi >> party[i].se;
            party[i].fi = (party[i].fi-8)*2;
            party[i].se = (party[i].se-8)*2;
        }
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int index = best(i, p);
            if(index >= 0){
                ++ans;
                party[index].fi = 32;
            }
        }
        cout << "On day " << cnt << " Emma can attend as many as " << ans << " parties.\n";
        ++cnt;
        cin >> p;
    }
    return 0;
}

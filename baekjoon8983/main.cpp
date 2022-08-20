#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M, L, ans = 0; cin >> M >> N >> L;
    ll S[M];
    vector<pii> coor;
    vector<ll> x;
    for(int i = 0; i < M; i++){
        cin >> S[i];
    }
    for(int i = 0, a, b; i < N; i++){
        cin >> a >> b;
        if(b <= L){
            coor.push_back({a, b});
        }
    }
    sort(coor.begin(), coor.end());
    int n = coor.size();
    for(int i = 0; i < n; i++){
        x.push_back(coor[i].first);
    }
    sort(S, S+M);
    ll idx;
    for(int i = 0; i < n; i++){
        idx = lower_bound(S, S+M, coor[i].first) - S;
        if(abs(coor[i].first - S[idx]) + coor[i].second <= L){
            ++ans;
        }
        else if(abs(coor[i].first - S[idx-1]) + coor[i].second <= L){
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}

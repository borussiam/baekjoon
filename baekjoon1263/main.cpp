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
    int N; cin >> N;
    vector<pi> t(N);
    for(int i = 0; i < N; i++){
        cin >> t[i].se >> t[i].fi;
    }
    sort(t.rbegin(), t.rend());
    int start = t[0].first;
    for(int i = 0; i < N; i++){
        start = min(start, t[i].first);
        start -= t[i].se;
    }
    if(start < 0){
        cout << "-1\n";
    }
    else{
        cout << start << '\n';
    }
    return 0;
}

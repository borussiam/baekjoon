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
    int N, M; cin >> N >> M;
    pi b[M];
    for(int i = 0; i < M; i++) cin >> b[i].fi >> b[i].se;
    sort(b, b+M);
    int s = 0, e = 0, room = N;
    for(int i = 0; i < M; i++){
        if(b[i].fi <= e && b[i].se > e){
            e = b[i].se;
        }
        else if(b[i].fi <= e && b[i].se <= e){
            continue;
        }
        else{
            room -= e-s;
            s = b[i].fi; e = b[i].se;
        }
    }
    room -= e-s;
    cout << room << '\n';
    return 0;
}

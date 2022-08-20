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
#define int ll

const int MAX = 3e5+5;
int N, K, C[MAX], ans = 0;
pi MV[MAX];
priority_queue<int> pq;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> MV[i].fi >> MV[i].se;
    for(int i = 0; i < K; i++) cin >> C[i];
    sort(MV, MV+N);
    sort(C, C+K);
    int mv = 0, c = -1;
    while(++c < K){
        while(mv < N && MV[mv].fi <= C[c]){
            pq.push(MV[mv++].se);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}

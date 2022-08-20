#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MAX = 2e5, MOD = 1e9+7;
ll N, seg1[800808], seg2[800808], len = 1;

ll sum1(ll L, ll R, ll curr, ll nodeL, ll nodeR)
{
    if(nodeR < L || R < nodeL){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return seg1[curr];
    }
    int mid = (nodeL + nodeR) / 2;
    return sum1(L, R, curr*2, nodeL, mid) + sum1(L, R, curr*2+1, mid+1, nodeR);
}

ll sum2(ll L, ll R, ll curr, ll nodeL, ll nodeR)
{
    if(nodeR < L || R < nodeL){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return seg2[curr];
    }
    int mid = (nodeL + nodeR) / 2;
    return sum2(L, R, curr*2, nodeL, mid) + sum2(L, R, curr*2+1, mid+1, nodeR);
}

void update1(ll loc)
{
    loc += len;
    seg1[loc] += 1;
    while(loc > 1){
        loc /= 2;
        seg1[loc] = seg1[loc*2] + seg1[loc*2+1];
    }
}

void update2(ll loc)
{
    loc += len;
    seg2[loc] += loc-len;
    while(loc > 1){
        loc /= 2;
        seg2[loc] = seg2[loc*2] + seg2[loc*2+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(seg1, 0, sizeof(seg1));
    memset(seg2, 0, sizeof(seg2));
    while(len < MAX){
        len *= 2;
    }
    cin >> N;
    ll ans = 1;
    for(int i = 0; i < N; i++){
        ll k; cin >> k;
        update1(k);
        update2(k);
        // cout << seg1[len+k] << ' ' << seg2[len+k] << '\n';
        if(i == 0){
            continue;
        }
        ll move = 0;
        move += (sum1(0, k-1, 1, 0, len-1)*k - sum2(0, k-1, 1, 0, len-1)) % MOD;
        move += (sum2(k+1, MAX-1, 1, 0, len-1) - sum1(k+1, MAX-1, 1, 0, len-1)*k) % MOD;
        // cout << move << '\n';
        ans = (ans * move) % MOD;
    }
    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M, len = 1;
ll arr[4000404];

ll sum(int L, int R, int curr, int nodeL, int nodeR)
{
    if(L > R){
        return sum(R, L, curr, nodeL, nodeR);
    }
    if(R < nodeL || nodeR < L){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return arr[curr];
    }
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, curr*2, nodeL, mid) + sum(L, R, curr*2+1, mid+1, nodeR);
}

void update(int loc, ll val)
{
    loc += len;
    arr[loc] = val;
    while(loc > 1){
        loc /= 2;
        arr[loc] = arr[loc*2] + arr[loc*2+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    while(N > len){
        len *= 2;
    }
    while(M--){
        ll i, j, k;
        cin >> i >> j >> k;
        if(i == 0){
            ll ans = sum(j-1, k-1, 1, 0, len-1);
            cout << ans << '\n';
        }
        else{
            update(j-1, k);
        }
    }
    return 0;
}

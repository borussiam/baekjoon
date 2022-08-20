#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int n, m, seg[800808], idx_arr[100001], len = 1;

int sum(int L, int R, int curr, int nodeL, int nodeR)
{
    if(nodeR < L || R < nodeL){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return seg[curr];
    }
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, curr*2, nodeL, mid) + sum(L, R, curr*2+1, mid+1, nodeR);
}

void update(int loc, int val)
{
    loc += len;
    seg[loc] = val;
    while(loc > 1){
        loc /= 2;
        seg[loc] = seg[loc*2] + seg[loc*2+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--){
        memset(seg, 0, sizeof(seg));
        memset(idx_arr, 0, sizeof(idx_arr));
        cin >> n >> m;
        while(len < n+m){
            len *= 2;
        }
        for(int i = 0; i < n; i++){
            seg[len + i] = 1;
            idx_arr[n-i] = i;
        }
        for(int i = len-1; i > 0; i--){
            seg[i] = seg[i*2] + seg[i*2+1];
        }
        int end = n;
        for(int i = 0, v; i < m; i++){
            cin >> v;
            int ans = sum(idx_arr[v]+1, n+m, 1, 0, len-1);
            cout << ans << ' ';
            update(idx_arr[v], 0);
            update(end, 1);
            idx_arr[v] = end;
            ++end;
        }
        cout << '\n';
    }
    return 0;
}

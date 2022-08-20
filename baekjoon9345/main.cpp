#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
int N, K, len = 1;
pii seg[400404];

pii min_max(int L, int R, int curr, int nodeL, int nodeR)
{
    if(nodeR < L || R < nodeL){
        return {INF, -1};
    }
    if(L <= nodeL && nodeR <= R){
        return seg[curr];
    }
    int mid = (nodeL + nodeR) / 2;
    pii left = min_max(L, R, curr*2, nodeL, mid), right = min_max(L, R, curr*2+1, mid+1, nodeR);
    int ret_min = min(left.first, right.first);
    int ret_max = max(left.second, right.second);
    return {ret_min, ret_max};
}

void update(int loc, int val)
{
    loc += len;
    seg[loc] = {val, val};
    while(loc > 1){
        loc /= 2;
        seg[loc] = {min(seg[loc*2].first, seg[loc*2+1].first), max(seg[loc*2].second, seg[loc*2+1].second)};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--){
        cin >> N >> K;
        for(int i = 0; i < 400404; i++){
            seg[i] = {INF, -1};
        }
        len = 1;
        while(len < N){
            len *= 2;
        }
        for(int i = 0; i < N; i++){
            seg[len+i] = {i, i};
        }
        for(int i = len-1; i > 0; i--){
            seg[i] = {min(seg[i*2].first, seg[i*2+1].first), max(seg[i*2].second, seg[i*2+1].second)};
        }
        for(int i = 0, Q, A, B; i < K; i++){
            cin >> Q >> A >> B;
            if(Q == 0){
                int a = seg[len+A].first, b = seg[len+B].first;
                update(A, b);
                update(B, a);
            }
            else{
                pii ret = min_max(A, B, 1, 0, len-1);
                // cout << ret.first << ' ' << ret.second << '\n';
                if(ret.first == A && ret.second == B){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}

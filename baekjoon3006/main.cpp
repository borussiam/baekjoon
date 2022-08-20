#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, seg[400404], arr[100101], arr_idx[100101], len = 1;

int sum(int L, int R, int curr, int nodeL, int nodeR)
{
    if(R < nodeL || nodeR < L){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return seg[curr];
    }
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, curr*2, nodeL, mid) + sum(L, R, curr*2+1, mid+1, nodeR);
}

void update(int loc)
{
    loc += len;
    seg[loc] = 0;
    while(loc > 1){
        loc /= 2;
        seg[loc] = seg[loc*2] + seg[loc*2+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while(len < N){
        len *= 2;
    }
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr_idx[arr[i]] = i;
        seg[len + i] = 1;
    }
    for(int i = len-1; i > 0; i--){
        seg[i] = seg[i*2] + seg[i*2+1];
    }
    for(int i = 0; i < N; i++){
        int idx, ans;
        if(i % 2){
            idx = arr_idx[N-(i/2)];
            ans = sum(idx+1, N-1, 1, 0, len-1);
        }
        else{
            idx = arr_idx[(i/2)+1];
            ans = sum(0, idx-1, 1, 0, len-1);
        }
        update(idx);
        cout << ans << '\n';
    }
    return 0;
}

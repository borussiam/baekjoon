#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int len = 1;
ll arr[404040];

ll sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(L>R) return sum(R, L, nodeNum, nodeL, nodeR);
    if(nodeR < L || R < nodeL) return 0;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

void update(int i, int val)
{
    i += len;
    arr[i] = val;
    while(i > 0){
        i /= 2;
        arr[i] = arr[i*2] + arr[i*2+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    while(len < N) len *= 2;
    for(int i = 0; i < N; i++) cin >> arr[i + len];
    for(int i = len - 1; i > 0; i--){
        arr[i] = arr[i*2] + arr[i*2+1];
    }
    while(Q--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << sum(x-1, y-1, 1, 0, len-1) << '\n';
        update(a-1, b);
    }
    return 0;
}

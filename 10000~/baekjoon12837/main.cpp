#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int len = 1;
ll m[4010101];

ll sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL && nodeR <= R) return m[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

void add(int i, ll val)
{
    i += len;
    m[i] += val;
    while(i > 0){
        i /= 2;
        m[i] = m[i*2] + m[i*2+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    while(len < N) len *= 2;
    while(Q--){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1) add(b - 1, c);
        else{
            cout << sum(b-1, c-1, 1, 0, len-1) << '\n';
        }
    }
    return 0;
}

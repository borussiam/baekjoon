#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll arr[4000400];
int len = 1;

ll mul(ll a, ll b)
{
    return (a * b) % MOD;
}

ll pro(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(nodeR < L || R < nodeL) return 1;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return mul(pro(L, R, nodeNum*2, nodeL, mid), pro(L, R, nodeNum*2+1, mid+1, nodeR));
}

void update(int i, ll val)
{
    i += len;
    arr[i] = val;
    while(i > 0){
        i /= 2;
        arr[i] = mul(arr[i*2], arr[i*2+1]);
    }
}

void print()
{
    int two = 1, cnt = 1;
    while(two < len*2){
        for(int i = 0; i < two; i++, cnt++){
            cout << arr[cnt] << ' ';
        }
        cout << '\n';
        two *= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0;i < 400400; i++) arr[i] = 1;
    int n, m, k; cin >> n >> m >> k;
    while(len < n) len *= 2;
    for(int i = 0; i < n; i++) cin >> arr[i + len];
    for(int i = len - 1; i > 0; i--){
        arr[i] = mul(arr[i*2], arr[i*2+1]);
    }
//    print();
    for(int i = 0; i < m + k; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            update(b - 1, c);
//            print();
        }
        else{
            cout << pro(b - 1, c - 1, 1, 0, len - 1) << '\n';
        }
    }
    return 0;
}

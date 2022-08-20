#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll Size = 1, arr[4040001];

ll sum(ll L, ll R, ll nodeNum, ll nodeL, ll nodeR)
{
    //현재 보고 있는 범위와 구하려는 범위가 겹치지 않을 때
    if(R < nodeL || L > nodeR) return 0;
    //현재 보고 있는 범위가 구하려는 범위 안에 포함될 때
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    //시작이 sum(L, R, 1, 0, N-1)이므로 mid는 항상 어떤 subtree의 오른쪽 자식을 나타냄이 보장됨
    ll mid = (nodeL + nodeR) / 2;
    //nodeNum*2, nodeNum*2+1 : 각각 포화 이진 트리에서 nodeNum의 좌,우 자식
    return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

void update(ll i, ll val)
{
    i += Size/2;
    arr[i] = val;
    while(i > 1){
        i /= 2; //부모 노드의 index
        arr[i] = arr[i*2] + arr[i*2+1];
    }
}

void print()
{
    int K=1,cnt=1;
    while(K!=Size){
        for(int i=0;i<K;i++){
            cout << arr[cnt] << ' ';
            cnt++;
        }
        K*=2;
        cout << '\n';
    }
//    cout << Size << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k; cin >> n >> m >> k;
    while(Size<n) Size*=2;
    Size *= 2;
    for(ll i = 0; i < n; i++){
        ll num; cin >> num;
        arr[Size / 2 + i] = num;
    }
    for(ll i = Size / 2 - 1; i > 0; i--){
        arr[i] = arr[2*i] + arr[2*i+1];
    }
//    print();
    for(ll i = 0; i < m + k; i++){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            update(b - 1, c);
//            print();
        }
        else{
            cout << sum(b - 1, c - 1, 1, 0, Size/2-1) << '\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

const int MAX = 1e9+1;
int len = 1;
pi seg[404040];

pi pair_comp(pi a, pi b)
{
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

pi find(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(nodeR < L || R < nodeL) return {MAX, 0};
    if(L <= nodeL && nodeR <= R) return seg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return pair_comp(find(L, R, nodeNum*2, nodeL, mid), find(L, R, nodeNum*2+1, mid+1, nodeR));
}

void print()
{
    int two=1,cnt=1;
    while(two<=len){
        for(int i=0;i<two;i++,cnt++){
            cout << '{' << seg[cnt].first << ' ' << seg[cnt].second << "} ";
        }
        cout << '\n';
        two *= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 404040; i++) seg[i] = {MAX, 0};
    int N, M; cin >> N >> M;
    while(len < N) len *= 2;
    for(int i = 0, in; i < N; i++){
        cin >> in;
        seg[i + len] = {in, in};
    }
    for(int i = len - 1; i > 0; i--){
        seg[i] = pair_comp(seg[i*2], seg[i*2+1]);
    }
//    print();
    for(int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        pi p = find(a - 1, b - 1, 1, 0, len - 1);
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}

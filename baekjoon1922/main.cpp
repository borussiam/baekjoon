#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX_N = 1e3, MAX_M = 1e5;

int uf[MAX_N];

int find(int a)
{
    if(uf[a] < 0){
        return a;
    }
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b){
        return false;
    }
    uf[b] = a;
    return true;
}

struct Edge{
    int u, v, w;
    Edge(): Edge(-1, -1, 0){}
    Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
    bool operator <(const Edge& O)const{
        return w < O.w;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Edge e[MAX_M];
    int N, M; cin >> N >> M;
    for(int i = 0, a, b, c; i < M; i++){
        cin >> a >> b >> c;
        e[i] = Edge(a, b, c);
    }
    sort(e, e+M);
    int ans = 0, cnt = 0;
    fill(uf, uf+N, -1);
    for(int i = 0; ; i++){
        if(merge(e[i].u, e[i].v)){
            ans += e[i].w;
            if(++cnt == N-1){
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

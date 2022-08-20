#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

struct Query{
    int q, idx, i, j, k;
};

const int MAX = 1e5, MAX_ST = 1<<19, start = MAX_ST / 2;
int N, M, seg[MAX_ST], ans[MAX];
vector<Query> v;

void upd(int loc)
{
    loc += start;
    ++seg[loc];
    while(loc > 1){
        loc /= 2;
        ++seg[loc];
    }
}

int sum(int s, int e, int node = 1, int ns = 0, int ne = start)
{
    if(e <= ns || ne <= s) return 0;
    if(s <= ns && ne <= e) return seg[node];
    int mid = (ns + ne) / 2;
    return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0, k; i < N; i++){
        cin >> k;
        v.pb({1, i, 0, 0, k});
    }
    cin >> M;
    for(int m = 0, a, b, c; m < M; m++){
        cin >> a >> b >> c;
        v.pb({2, m, a, b, c});
    }
    sort(v.begin(), v.end(), [&](Query &a, Query &b){
        return (a.k == b.k) ? (a.q > b.q) : (a.k > b.k);
    });
    for(auto q : v){
        // printf("%d ", q.q);
        if(q.q == 1){
            // printf("%d\n", q.idx);
            upd(q.idx);
        }
        else{
            ans[q.idx] = sum(q.i-1, q.j);
            // printf("%d %d %d\n", q.idx, q.i-1, q.j);
        }
        // for(int i = start; i < start+N; i++) printf("%d ", seg[i]);
        // printf("\n");
    }
    for(int i = 0; i < M; i++) cout << ans[i] << '\n';
    return 0;
}

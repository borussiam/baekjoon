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

const int MAX = 1e5, MAX_ST = 1<<19, start = MAX_ST / 2;
int N, M, L = 0;
vector<int> mst[MAX_ST];

int gt(int s, int e, int k, int node = 1, int ns = 0, int ne = start)
{
    if(e <= ns || ne <= s) return 0;
    if(s <= ns && ne <= e){
        return mst[node].end() - upper_bound(mst[node].begin(), mst[node].end(), k);
    }
    int mid = (ns + ne) / 2;
    return gt(s, e, k, node*2, ns, mid) + gt(s, e, k, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0, k; i < N; i++){
        cin >> k;
        mst[start+i].pb(k);
    }
    for(int i = start-1; i > 0; i--){
        vector<int> &c = mst[i], &l = mst[i*2], &r = mst[i*2+1];
        c.resize(l.size() + r.size());
        for(int j = 0, p = 0, q = 0; j < c.size(); j++){
            if(q == r.size() || (p < l.size() && l[p] < r[q])){
                c[j] = l[p++];
            }
            else c[j] = r[q++];
        }
    }
    cin >> M;
    while(M--){
        int s, e, k; cin >> s >> e >> k;
        L = gt((s^L)-1, e^L, k^L);
        cout << L << '\n';
    }
    return 0;
}

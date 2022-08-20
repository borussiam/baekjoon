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

const ll MAX = 5e5, MAX_ST = 1<<20, start = 1<<19;
ll N, seg[MAX_ST];

void update(int loc)
{
    loc += start;
    ++seg[loc];
    while(loc > 1){
        loc /= 2;
        ++seg[loc];
    }
}

int sum(int s, int e, int node, int ns, int ne)
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
    vector<int> X(N);
    for(auto &i : X) cin >> i;
    auto comp = X;
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for(auto &i : X){
        i = lower_bound(comp.begin(), comp.end(), i) - comp.begin();
    }
    for(auto &i : X){
        cout << sum(i, (int)MAX, 1, 0, start) + 1 << '\n';
        update(i);
    }
    return 0;
}

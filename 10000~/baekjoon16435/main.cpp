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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L; cin >> N >> L;
    int h[N];
    for(int i = 0; i < N; i++) cin >> h[i];
    sort(h, h+N);
    int idx = 0;
    while(idx < N && L >= h[idx]){
        ++idx; ++L;
    }
    cout << L << '\n';
    return 0;
}

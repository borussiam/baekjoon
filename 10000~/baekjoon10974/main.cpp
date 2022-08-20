#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define fi first
#define se second
#define pb push_back

int chk[10];
vector<int> v;

void solve(int N, int cnt = 0)
{
    if(cnt >= N){
        for(int i : v) cout << i << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(chk[i]) continue;
        chk[i] = true;
        v.pb(i);
        solve(N, cnt+1);
        chk[i] = false;
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N; cin >> N;
    solve(N);
    return 0;
}

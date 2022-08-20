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

const ll MAX = 4e6;
bool prime[MAX+1];
vector<ll> p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(prime, prime+MAX+1, true);
    prime[0] = prime[1] = 0;
    for(ll i = 2; i <= MAX; i++){
        if(prime[i]){
            p.pb(i);
            ll k = i;
            while(i*k <= MAX){
                prime[i*k] = false;
                ++k;
            }
        }
    }
    // for(int i = 0; i < 10; i++) cout << p[i] << ' ';
    int n = p.size();
    int s = 0, e = 0, sum = 0, ans = 0;
    int N; cin >> N;
    while(true){
        if(sum >= N) sum -= p[s++];
        else if(e == n) break;
        else sum += p[e++];
        if(sum == N) ++ans;
    }
    cout << ans << '\n';
    return 0;
}

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
    int N; cin >> N;
    string s[N];
    for(int i = 0; i < N; i++) cin >> s[i];
    sort(s, s+N);
    if(s[N-1] == "0"){
        cout << "0\n";
    }
    else{
        for(int i = N-1; i >= 0; i--){
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}

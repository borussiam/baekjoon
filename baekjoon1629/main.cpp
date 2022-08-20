#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll C;

ll mul(ll a, ll b)
{
    if(b==0){
        return 1%C;
    }
    if(b==1){
        return a%C;
    }
    if(b%2){
        return (a*((mul(a, b/2)*mul(a, b/2))%C))%C;
    }
    return (mul(a, b/2)*mul(a, b/2))%C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A, B; cin >> A >> B >> C;
    cout << mul(A, B) << '\n';
    return 0;
}

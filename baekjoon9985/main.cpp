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

struct State{
    int r, c;
    vector<int> g;
    State(): State(0){}
    State(int D)
    {
        r = c = -1;
        g.resize(D*D);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int D, N;
    while(cin >> s >> D >> N){

    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MAX = 100;
const ll LIM = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pii ncr[MAX+1][MAX+1];
    for(int i = 0; i < MAX+1; i++){
        ncr[i][0] = ncr[i][i] = {1, 0};
    }
    for(int i = 2; i < MAX+1; i++){
        for(int j = 1; j < i; j++){
            ncr[i][j].first = ncr[i-1][j-1].first + ncr[i-1][j].first;
            ncr[i][j].second = ncr[i-1][j-1].second + ncr[i-1][j].second;
            ll q = ncr[i][j].first / LIM, r = ncr[i][j].first % LIM;
            ncr[i][j].first = r;
            ncr[i][j].second += q;
        }
    }
    int n, m; cin >> n >> m;
    if(ncr[n][m].second){
        cout << ncr[n][m].second;
        cout << setw(18) << setfill('0') << ncr[n][m].first << '\n';
    }
    else{
        cout << ncr[n][m].first << '\n';
    }
    return 0;
}

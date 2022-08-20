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
    int M, N; cin >> M >> N;
    vector<vector<pi> > p(M, vector<pi>(N));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> p[i][j].fi;
            p[i][j].se = j;
        }
    }
    int ans = M*(M-1)/2;
    for(int i = 0; i < M; i++){
        vector<pi> vec = p[i];
        sort(vec.begin(), vec.end());
        for(int j = i+1; j < M; j++){
            for(int k = 1; k < N; k++){
                int idx1 = vec[k-1].se, idx2 = vec[k].se;
                if(vec[k-1].fi == vec[k].fi){
                    if(p[j][idx1].fi != p[j][idx2].fi){
                        --ans;
                        break;
                    }
                }
                else if(p[j][idx1].fi >= p[j][idx2].fi){
                    --ans;
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int arr[4][n];
    for(int j = 0; j < n; j++){
        for(int i = 0; i < 4; i++){
            cin >> arr[i][j];
        }
    }
    vector<int> ab, cd;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ab.push_back(-(arr[0][i] + arr[1][j]));
            cd.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    ll ans = 0;
    for(int &sum : ab){
        int idx1 = lower_bound(cd.begin(), cd.end(), sum) - cd.begin();
        int idx2 = upper_bound(cd.begin(), cd.end(), sum) - cd.begin();
        ans += idx2 - idx1;
    }
    cout << ans << '\n';
    return 0;
}

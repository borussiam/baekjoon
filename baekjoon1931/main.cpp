#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans=1; cin >> n;
    pair<int, int> t[n];
    for(int i = 0; i < n; i++){
        cin >> t[i].second >> t[i].first;
    }
    sort(t, t+n);
    int e=t[0].first;
    for(int i = 1; i < n; i++){
        if(t[i].second>=e){
            ++ans;
            e=t[i].first;
        }
    }
    cout << ans << '\n';
    return 0;
}

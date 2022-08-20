#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n], d[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        d[i] = n + 1;
    }
    for(int i = 0; i < n; i++){
        int idx = lower_bound(d, d+n, a[i]) - d;
        d[idx] = a[i];
    }
    int len = lower_bound(d, d+n, n+1) - d;
    cout << n - len << '\n';
    return 0;
}

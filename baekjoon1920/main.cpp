#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cin >> m;
    for(int i = 0, b; i < m; i++){
        cin >> b;
        if(binary_search(a, a+n, b)){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
    return 0;
}

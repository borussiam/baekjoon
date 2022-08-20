#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h[1001] = {0}, high[1001] = {0}, max_h = 0, ans = 0, temp = 0;
    cin >> n;
    for(int i = 0, l; i < n; i++){
        cin >> l; cin >> h[l];
        if(h[l] > h[max_h]) max_h = l;
    }
    for(int i = 1; i <= max_h; i++){
        if(h[i] > temp) temp = h[i];
        high[i] = temp;
    }
    temp = 0;
    for(int i = 1000; i > max_h; i--){
        if(h[i] > temp) temp = h[i];
        high[i] = temp;
    }
    for(int i = 1; i <= 1000; i++) ans += high[i];
    cout << ans << '\n';
    return 0;
}

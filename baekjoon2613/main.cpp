#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, mx = 0, sum = 0; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if(mx < a[i]) mx = a[i];
    }
    int l = max(mx, (sum+m-1)/m), r = 30000;
    while(l < r){
        int mnmx = (l + r) / 2;
        int temp = 0, cnt = 1;
        for(int i = 0; i < n; i++){
            temp += a[i];
            if(temp > mnmx) temp = a[i], ++cnt;
        }
        if(cnt <= m) r = mnmx;
        else l = mnmx + 1;
    }
    vector<int> ans;
    int temp = 0, cnt = 0;
    for(int i = 0; i <= n; i++){
        if(i == n){
            ans.push_back(cnt);
            // cout << "1pushed " << cnt << '\n';
            break;
        }
        temp += a[i]; ++cnt;
        if(temp > r){
            temp = a[i];
            ans.push_back(cnt-1);
            // cout << "2pushed " << cnt-1 << '\n';
            cnt = 1;
        }
    }
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << ' ';
    // }
    // cout << '\n';
    if(ans.size() < m){
        int dif = m-ans.size();
        int count = 0, it = 1;
        vector<int>::iterator iter = ans.end();
        --iter;
        // cout << (*iter) << '\n';
        while(count < dif){
            if((*iter) > 1){
                count += (*iter)-1;
                it += (*iter)-1;
                ans.insert(++iter, (*iter)-1, 1);
                iter = ans.end();
                for(int i = 0; i < it; i++) --iter;
                (*iter) = 1;
            }
            --iter;
            ++it;
        }
    }
    cout << r << '\n';
    for(int i = 0; i < m; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}

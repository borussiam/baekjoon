#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 5e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n], parent[MAX+1] = {-1,};
    vector<pii> v;
    vector<int> lis(1, 0);
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        a[i] = v[i].second;
    }
    for(int i = 0; i < n; i++){
        if(a[i] > lis.back()){
            parent[a[i]] = lis.back();
            lis.push_back(a[i]);
        }
        else{
            int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[idx] = a[i];
            parent[a[i]] = lis[idx-1];
        }
    }
    int ans = n - (lis.size()-1);
    cout << ans << '\n';
    stack<int> s;
    int track = lis.back();
    while(parent[track] != -1){
        s.push(track);
        track = parent[track];
    }
    // cout << "RE\n\n";
    // while(!s.empty()){
    //     cout << s.top() << '\n';
    //     s.pop();
    // }
    for(int i = 0; i < n; i++){
        if(!s.empty() && s.top() == a[i]){
            s.pop();
            continue;
        }
        cout << v[i].first << '\n';
    }
    return 0;
}

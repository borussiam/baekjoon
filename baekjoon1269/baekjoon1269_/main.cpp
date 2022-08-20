#include <bits/stdc++.h>
using namespace std;
vector<int> a,b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,inter=0; cin >> n >> m;
    for(int i=0,k;i<n;i++){
        cin >> k;
        a.push_back(k);
    }
    sort(a.begin(),a.end());
    for(int i=0,k;i<m;i++){
        cin >> k;
        if(binary_search(a.begin(),a.end(),k))
            inter++;
    }
    cout << n+m-2*inter << '\n';
    return 0;
}

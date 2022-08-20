#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n+1],len=0;
    vector<int> d{-1};
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        if(a[i]>d.back()){
            d.push_back(a[i]);
            len++;
        }
        else{
            int idx=lower_bound(d.begin(),d.begin()+len,a[i])-d.begin();
            d[idx]=a[i];
        }
    }
    cout << n-len << '\n';
    return 0;
}

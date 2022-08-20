#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int cas=1;cas<=t;cas++){
        int n;
        cin >> n;
        int*a=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<n;i++) cin >> a[i];
        int ans=0;
        for(int k=0;k<n;k++){
            vector<int> d{-1};
            int len=0;
            for(int i=k;i<n;i++){
                if(i==k||a[i]>d.back()){
                    d.push_back(a[i]);
                    len++;
                }
                else{
                    int idx=lower_bound(d.begin(),d.begin()+len,a[i])-d.begin();
                    d[idx]=a[i];
                }
                ans+=len;
            }
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }
    return 0;
}

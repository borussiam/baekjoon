#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q,a;
    cin >> n >> q;
    int sum[n]={0};
    cin >> a;
    for(int i=1;i<n;i++){
        int b; cin >> b;
        sum[i]=abs(b-a)+sum[i-1];
        a=b;
    }
    for(int i=0;i<q;i++){
        int l,r; cin >> l >> r;
        if(r-1<l){
            cout << "0\n"; continue;
        }
        cout << sum[r-1]-sum[l-1] << '\n';
    }
    return 0;
}

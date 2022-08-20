#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}

ll s(ll*a,ll n)
{
    if(n==1) return a[0];
    ll ret=max(s(a,(n+1)/2),s(a+(n+1)/2,n-(n+1)/2));
    ll lo=(n-1)/2,hi=(n+1)/2,mxh=min(a[lo],a[hi]),w=2;
    ll S=w*mxh;
    while(lo!=0||hi!=n-1){
        if(hi==n-1){
            mxh=min(mxh,a[lo-1]);
            lo--;
            w++;
            S=maxll(S,w*mxh);
        }
        else if(lo==0||a[hi+1]>a[lo-1]){
            mxh=min(mxh,a[hi+1]);
            hi++;
            w++;
            S=maxll(S,w*mxh);
        }
        else{
            mxh=min(mxh,a[lo-1]);
            lo--;
            w++;
            S=maxll(S,w*mxh);
        }
    }
    ret=maxll(ret,S);
    return ret;
}

int main()
{
    ll a[100050],n;
    while(1){
        memset(a,0,sizeof(a));
        cin >> n;
        if(n==0) return 0;
        for(int i=0;i<n;i++) cin >> a[i];
        ll ans=s(a,n);
        cout << ans << "\n";
    }
}

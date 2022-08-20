#include <iostream>

using namespace std;

int s(int*a,int n)
{
    if(n==1) return a[0];
    int ret=max(s(a,(n+1)/2),s(a+(n+1)/2,n-(n+1)/2));
    int lo=(n-1)/2,hi=(n+1)/2,mxh=min(a[lo],a[hi]),w=2,S=w*mxh;
    while(lo!=0||hi!=n-1){
        if(hi==n-1){
            mxh=min(mxh,a[lo-1]);
            lo--;
            w++;
            S=max(S,w*mxh);
        }
        else if(lo==0||a[hi+1]>a[lo-1]){
            mxh=min(mxh,a[hi+1]);
            hi++;
            w++;
            S=max(S,w*mxh);
        }
        else{
            mxh=min(mxh,a[lo-1]);
            lo--;
            w++;
            S=max(S,w*mxh);
        }
    }
    ret=max(ret,S);
    return ret;
}

int main()
{
    int n;
    cin >> n;
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) cin >> a[i];
    int ans=s(a,n);
    cout << ans << "\n";
    return 0;
}

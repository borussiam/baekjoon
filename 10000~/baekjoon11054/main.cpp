#include <iostream>

using namespace std;

int main()
{
    int n,a[1005]={0},b[1005]={0},d1[1005]={0},d2[1005]={0},ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[n-i+1]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&d1[i]<d1[j]+1)
                d1[i]=d1[j]+1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n+1;j>i;j--){
            if(a[i]>a[j]&&d2[i]<d2[j]+1)
                d2[i]=d2[j]+1;
        }
    }
    for(int i=1;i<=n;i++) ans=max(ans,d1[i]+d2[i]-1);
    cout << ans << endl;
    return 0;
}

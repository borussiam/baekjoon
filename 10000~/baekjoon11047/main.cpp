#include <iostream>

using namespace std;

int main()
{
    int n,k,a[10],ans=0;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=n-1;i>=0;i--){
        int cnt=k/a[i];
        k%=a[i];
        ans+=cnt;
    }
    cout << ans << endl;
    return 0;
}

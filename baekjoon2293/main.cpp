#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int d[n],a[k+1]={0};
    for(int i=0;i<n;i++) cin >> d[i];
    sort(d,d+n);
    for(int i=0;i*d[0]<=k;i++) a[i*d[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=k;j>=0;j--){
            for(int l=1;j+l*d[i]<=k;l++)
                a[j+l*d[i]]+=a[j];
        }
    }
    cout << a[k] << endl;
    return 0;
}

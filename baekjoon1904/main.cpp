#include <bits/stdc++.h>
#define MOD 15746

using namespace std;

int main()
{
    int n,a[3]={1,2,3},i;
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    if(n==2){
        cout << 2;
        return 0;
    }
    for(i=3;i<n;i++) a[i%3]=(a[(i+1)%3]+a[(i+2)%3])%MOD;
    cout << a[(i+2)%3] << endl;
    return 0;
}

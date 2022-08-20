#include <iostream>

using namespace std;

int f(int n)
{
    int ret=1;
    for(int i=2;i<=n;i++) ret*=i;
    return ret;
}

int main()
{
    int n,k;
    cin >> n >> k;
    int ans=f(n)/(f(k)*f(n-k));
    cout << ans << endl;
    return 0;
}

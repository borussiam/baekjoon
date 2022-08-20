#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll memo[10005];

ll fi(int n)
{
    ll& ret=memo[n];
    if(ret!=-1) return ret;
    if(n==0) return ret=0;
    if(n==1) return ret=1;
    return ret=fi(n-1)+fi(n-2);
}

int main()
{
    memset(memo,-1,sizeof(memo));
    int n;
    cin >> n;
    cout << fi(n) << endl;
    return 0;
}

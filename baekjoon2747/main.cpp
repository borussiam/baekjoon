#include <bits/stdc++.h>

using namespace std;

int memo[10005];

int fi(int n)
{
    int& ret=memo[n];
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

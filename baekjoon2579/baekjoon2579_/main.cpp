#include <iostream>
#include <cstring>

using namespace std;

int memo[300],p[300];

int f(int n)
{
    if(n<0) return 0;
    if(n==0) return p[0];
    if(n==1) return p[0]+p[1];
    int& ret=memo[n];
    if(ret!=-1) return ret;
    ret=max(f(n-3)+p[n-1]+p[n],f(n-2)+p[n]);
    return ret;
}

int main()
{
    memset(memo,-1,sizeof(memo));
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    cout << f(n-1) << endl;
    return 0;
}

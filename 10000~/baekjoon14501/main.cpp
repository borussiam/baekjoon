#include <iostream>
#include <cstring>

using namespace std;

int n,memo[20],T[20],P[20];

int f(int d)
{
    if(d>n) return 0;
    int& ret=memo[d];
    if(ret!=-1) return ret;
    if(d+T[d]==n+1) return max(f(d+1),P[d]);
    if(d+T[d]>n+1){
        return ret=f(d+1);
    }
    return ret=max(f(d+1),f(d+T[d])+P[d]);
}

int main()
{
    memset(memo,-1,sizeof(memo));
    cin >> n;
    for(int i=1;i<=n;i++) cin >> T[i] >> P[i];
    cout << f(1) << "\n";
    return 0;
}

#include <iostream>
#include <cstring>
#define MOD 10007

using namespace std;

int memo[1005];

int f(int n)
{
    if(memo[n]!=-1) return memo[n];
    int& ret=memo[n];
    return ret=(f(n-1)+2*f(n-2))%MOD;
}

int main()
{
    memset(memo,-1,sizeof(memo));
    memo[0]=0;
    memo[1]=1;
    memo[2]=3;
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}

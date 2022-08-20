#include <iostream>
#include <cstring>
typedef long long ll;

using namespace std;

ll memo[100];

ll pinary(int n)
{
    if(n<1) return 0;
    if(n==1) return 1;
    if(n==2) return 1;
    if(memo[n]!=-1) return memo[n];
    ll& ret=memo[n];
    return ret=2*pinary(n-2)+pinary(n-3);
}

int main()
{
    memset(memo,-1,sizeof(memo));
    int n;
    cin >> n;
    cout << pinary(n) << endl;
    return 0;
}

#include <iostream>
#include <cstring>
typedef long long ll;

using namespace std;

ll memo[105];

ll f(int n)
{
    if(memo[n]!=-1) return memo[n];
    ll& ret=memo[n];
    return ret=f(n-1)+f(n-5);
}

int main()
{
    for(int i=0;i<105;i++) memo[i]=-1;
    memo[0]=0;
    memo[1]=memo[2]=memo[3]=1;
    memo[4]=memo[5]=2;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}

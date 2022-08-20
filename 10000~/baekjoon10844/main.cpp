#include <iostream>
#include <cstring>
#define MAX 1000000000

using namespace std;

int memo[105][10];

int s(int n,int k)
{
    if(n==1){
        if(k==0) return 0;
        return 1;
    }
    if(memo[n][k]!=-1) return memo[n][k];
    int& ret=memo[n][k];
    if(k==0) ret=s(n-1,1);
    else if(1<=k&&k<=8) ret=(s(n-1,k-1)+s(n-1,k+1))%MAX;
    else ret=s(n-1,8);
    return ret;
}

int main()
{
    for(int i=0;i<105;i++) memset(memo[i],-1,sizeof(memo[i]));
    int n;
    cin >> n;
    int ans=0;
    for(int k=0;k<10;k++){
        ans=(ans+s(n,k))%MAX;
    }
    cout << ans << endl;
    return 0;
}

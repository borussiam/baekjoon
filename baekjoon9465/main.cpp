#include <iostream>
#include <cstring>

using namespace std;

int memo[100050*2],p[100050*2];

int f(int n,int k)
{
    int& ret=memo[n*2+k-2];
    if(ret!=-1) return ret;
    return ret=max(f(n-1,(k%2)+1),f(n-2,(k%2)+1))+p[n*2+k-2];
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        memset(memo,-1,sizeof(memo));
        cin >> n;
        for(int i=1;i<=n;i++) cin >> p[i*2-1];
        for(int i=1;i<=n;i++) cin >> p[i*2];
        memo[1]=p[1]; memo[2]=p[2]; memo[3]=p[2]+p[3]; memo[4]=p[1]+p[4];
        cout << max(f(n,1),f(n,2)) << "\n";
    }
    return 0;
}

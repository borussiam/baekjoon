#include <iostream>
#include <cstring>

using namespace std;

int memo[300][2],p[300];
int f(int n,int k)
{
    if(n<0) return 0;
    if(n==0){
        memo[0][0]=p[0];
    }
    int& ret=memo[n][k];
    if(ret!=-1) return ret;
    if(k==0) ret=p[n]+max(f(n-2,0),f(n-2,1));
    if(k==1) ret=p[n]+f(n-1,0);
    return ret;
}

int g(int n)
{
    return max(f(n,0),f(n,1));
}

int main()
{
    memset(memo,-1,sizeof(memo));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int ret=g(n-1);
    cout << ret << endl;
    return 0;
}

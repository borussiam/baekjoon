#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n)
{
    if(n==2) return true;
    if(n<2||n%2==0) return false;
    ll i=3;
    while(i*i<=n){
        if(n%i==0) return false;
        i++;
    }
    return true;
}

ll nextPrime(ll n)
{
    while(!isPrime(n+1)) n++;
    return n+1;
}

int main()
{
    ll mn,mx;
    cin >> mn >> mx;
    int*a=(int*)calloc(mx-mn+1,sizeof(int));
    ll p=2;
    while(p*p<=mx){
        ll init=(mn%(p*p)==0 ? mn : mn+p*p-(mn%(p*p)))-mn;
        while(init<=mx-mn){
            a[init]=1;
            init+=p*p;
        }
        p=nextPrime(p);
    }
    int ans=0;
    for(int i=0;i<mx-mn+1;i++)
        if(a[i]==0) ans++;
    cout << ans << '\n';
    return 0;
}

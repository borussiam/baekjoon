#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isPrime(int n)
{
    if(n==1){
        return false;
    }
    if(n==2 || n==3){
        return true;
    }
    int i=2;
    while(i*i<=n){
        if(n%i==0){
            return false;
        }
        ++i;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans=0; cin >> n;
    for(int i = 0, a; i < n; i++){
        cin >> a;
        if(isPrime(a)){
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}

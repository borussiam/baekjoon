#include <bits/stdc++.h>

using namespace std;

int power(int a,int b)
{
    int ret=1;
    for(int i=0;i<b;i++) ret*=a;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    while(N!=0){
        int n=N,p=2,cnt=0,ans=1,flag=0;
        while(flag<2){
            if(n%p==0){
                n/=p;
                cnt++;
            }
            else{
                if(cnt>0) ans*=(p-1)*power(p,cnt-1);
                cnt=0;
                p++;
            }
            if(p*p>n) flag++;
        }
        if(cnt>0) ans*=(p-1)*power(p,cnt-1);
        if(n!=1) ans*=n-1;
        cout << ans << "\n";
        cin >> N;
    }
    return 0;
}

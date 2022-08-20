#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[46] = {0, 1,};

ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
    ll g = a; x = 1, y = 0;
    if(b) g = ext_gcd(b, a%b, y, x), y -= (a/b) * x;
    return g;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i <= 45; i++) fib[i] = fib[i-1] + fib[i-2];
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        int pos = upper_bound(fib, fib+46, n-1) - fib;
//        cout << pos << '\n';
        for(int j = pos; j >= 2; j--){
            ll b, a;
            ext_gcd(fib[j], fib[j-1], b, a);
            b *= n, a *= n;
//            cout << a << ' ' << b << '\n';
            if(a<=0){
                ll k = ((-a)+fib[j]-1)/fib[j];
                b-=k*fib[j-1], a+=k*fib[j];
                if(a==0) b-=fib[j-1], a+=fib[j];
                while(a+fib[j]<=b-fib[j-1]) b-=fib[j-1], a+=fib[j];
                while(a>b) b+=fib[j-1], a-=fib[j];
//                    if(a>0&&b>0&&a<=b){
//                        cout << "a: " << a << ' ' << b << '\n';
//                        break;
//                    }
            }
            if(b<=0){
                ll k = ((-b)+fib[j-1]-1)/fib[j-1];
                b+=k*fib[j-1], a-=k*fib[j];
                if(b==0) b+=fib[j-1], a-=fib[j];
                while(a+fib[j]<=b-fib[j-1]) b-=fib[j-1], a+=fib[j];
                while(a>b) b+=fib[j-1], a-=fib[j];
//                    if(a>0&&b>0&&a<=b){
//                        cout << "b: " << a << ' ' << b << '\n';
//                        break;
//                    }
            }
            if(a>0&&b>0&&a<=b){
                cout << a << ' ' << b << '\n';
                break;
            }
//            cout << "k=" << j << ", " << a << ' ' << b << '\n';
        }
    }
    return 0;
}

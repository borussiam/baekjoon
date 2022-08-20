#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int x, int y)
{
    if(y==0){
        return x;
    }
    return x>=y ? gcd(y, x-y) : gcd(y, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << '\n' << a*b/gcd(a, b) << '\n';
    return 0;
}

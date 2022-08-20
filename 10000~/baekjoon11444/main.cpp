#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int MOD=1000000007;
const int M[2][2]={{1,1},{1,0}};
ll F[2][2]={{1,1},{1,0}};

void multiply()
{
    ll f[2][2]={{F[0][0],F[0][1]},{F[1][0],F[1][1]}};
    F[0][0]=(f[0][0]*M[0][0]+f[0][1]*M[1][0])%MOD;
    F[0][1]=(f[0][0]*M[0][1]+f[0][1]*M[1][1])%MOD;
    F[1][0]=(f[1][0]*M[0][0]+f[1][1]*M[1][0])%MOD;
    F[1][1]=(f[1][0]*M[0][1]+f[1][1]*M[1][1])%MOD;
}

void square()
{
    ll f[2][2]={{F[0][0],F[0][1]},{F[1][0],F[1][1]}};
    F[0][0]=(f[0][0]*f[0][0]+f[0][1]*f[1][0])%MOD;
    F[0][1]=(f[0][0]*f[0][1]+f[0][1]*f[1][1])%MOD;
    F[1][0]=(f[1][0]*f[0][0]+f[1][1]*f[1][0])%MOD;
    F[1][1]=(f[1][0]*f[0][1]+f[1][1]*f[1][1])%MOD;
}

void power(ll n)
{
    if(n==0||n==1) return;
    power(n/2);
    square();
    if(n%2) multiply();
}

ll fi(ll n)
{
    if(n==0) return 0;
    power(n-1);
    return F[0][0];
}

int main()
{
    ll n;
    cin >> n;
    cout << fi(n) << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

const int MAX = 1e5+5, MAX_ST = 1<<19, start = MAX_ST/2;
const ll MOD = 1e9+7;
ll matrix[2][2] = {{1, 1}, {1, 0}};

class mat{

public:
    ll m[2][2];
    ll tmp[2][2];

    mat(){
        m[0][0] = 1;
        m[0][1] = 1;
        m[1][0] = 1;
        m[1][1] = 0;
    }

    mat& operator =(const mat& b)
    {
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                m[i][j] = b.m[i][j];
            }
        }
        return *this;
    }

    ll (*ad(ll a[][2], ll b[][2]))[2]
    {
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                tmp[i][j] = (a[i][j] + b[i][j]) % MOD;
            }
        }
        return tmp;
    }

    ll (*mul(ll a[][2], ll b[][2]))[2]
    {  
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                tmp[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    tmp[i][j] += (a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return tmp;
    }

    static void assign(ll s[][2], ll d[][2])
    {
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                s[i][j] = d[i][j];
            }
        }
    }

    void power(ll a[][2], const int& n)
    {
        ll ret[2][2];
        if(n == 1){
            assign(m, mul(m, a));
            return;
        }
        if(n%2 == 0){
            assign(ret, mul(a, a));
            power(ret, n/2);
            return;
        }
        else{
            assign(ret, mul(a, a));
            power(ret, n/2);
            assign(m, mul(m, a));
            return;
        }
    }

    // mat& operator ^(const int& n)
    // {
    //     if(n == 1) return *this;
    //     if(n%2 == 0){
    //         mul(m, m);
    //         return (m)^(n/2);
    //     }
    //     else{
    //         return (((*this)*(*this))^(n/2))*(*this);
    //     }
    // }
};

class SegTree{

public:
    mat seg[MAX_ST];
    ll lazy[MAX_ST];

    void add(int s, int e){ add(s, e, 1, 0, start); }
    ll sum(int s, int e){ return sum(s, e, 1, 0, start); }

private:

    void propagate(int node, int ns, int ne)
    {
        if(lazy[node] != 0){
            if(node < start){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            ll temp[2][2];
            mat::assign(temp, seg[node].m);
            seg[node].power(matrix, lazy[node]);
            lazy[node] = 0;
        }
    }

    void add(int s, int e, int node, int ns, int ne)
    {
        propagate(node, ns, ne);
        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e){
            ++lazy[node];
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns + ne) / 2;
        add(s, e, node*2, ns, mid);
        add(s, e, node*2+1, mid, ne);
        mat::assign(seg[node].m, seg[node].ad(seg[node*2].m, seg[node*2+1].m));
        // seg[node] = mat::ad(seg[node*2].m, seg[node*2+1].m);
    }

    ll sum(int s, int e, int node, int ns, int ne)
    {
        propagate(node, ns, ne);
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return seg[node].m[1][1];
        int mid = (ns + ne) / 2;
        return (sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne)) % MOD;
    }
};


ll n, k, a, b;
char c;
SegTree seg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = start-1; i > 0; i--){
        // seg.seg[i] = seg.seg[i*2] + seg.seg[i*2+1];
        mat::assign(seg.seg[i].m, seg.seg[i].ad(seg.seg[i*2].m, seg.seg[i*2+1].m));
        // cout << seg.seg[i].m[0][1] << '\n';
    }
    // int cnt = 1;
    // for(int i = 0; i < 5; i++){
    //     for(cnt; cnt < (1<<i); cnt++)
    //         printf("%d ", seg.seg[cnt].m[1][1]);
    //     printf("\n");
    // }
    // cnt = 1;
    // for(int i = 0; i < 5; i++){
    //     for(cnt; cnt < (1<<i); cnt++)
    //         printf("%d ", seg.lazy[cnt]);
    //     printf("\n");
    // }
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         cout << test.m[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // mat::assign(test.m, test.mul(test.m, test.m));
    // for(int k = 1; k < 10; k++){
    //     mat test;
    //     ll matrix[2][2] = {{1, 1}, {1, 0}};
    //     test.power(matrix, k);
    //     for(int i = 0; i < 2; i++){
    //         for(int j = 0; j < 2; j++){
    //             cout << test.m[i][j] << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }
    while(k--){
        cin >> c >> a >> b;
        if(c == 'D'){
            seg.add(a-1, b);
        }
        else{
            cout << seg.sum(a-1, b) << '\n';
        }
        // cnt = 1;
        // for(int i = 0; i < 5; i++){
        //     for(cnt; cnt < (1<<i); cnt++)
        //         printf("%d ", seg.seg[cnt].m[1][1]);
        //     printf("\n");
        // }
        // cnt = 1;
        // for(int i = 0; i < 5; i++){
        //     for(cnt; cnt < (1<<i); cnt++)
        //         printf("%d ", seg.lazy[cnt]);
        //     printf("\n");
        // }
    }
    return 0;
}

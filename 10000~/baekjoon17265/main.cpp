#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a[5][5], mx[5][5], mn[5][5];

int operate(int a, int oper, int b)
{
    if(oper == -1){
        return a + b;
    }
    else if(oper == -2){
        return a - b;
    }
    else{
        return a * b;
    }
}

void open(int i, int j)
{
    mx[i][j] = max(max(operate(mx[i-1][j-1], a[i-1][j], a[i][j]), operate(mx[i-1][j-1], a[i][j-1], a[i][j])), max(operate(mx[i-2][j], a[i-1][j], a[i][j]), operate(mx[i][j-2], a[i][j-1], a[i][j])));
    mn[i][j] = min(min(operate(mn[i-1][j-1], a[i-1][j], a[i][j]), operate(mn[i-1][j-1], a[i][j-1], a[i][j])), min(operate(mn[i-2][j], a[i-1][j], a[i][j]), operate(mn[i][j-2], a[i][j-1], a[i][j])));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            if(c == '+') a[i][j] = -1;
            else if(c == '-') a[i][j] = -2;
            else if(c == '*') a[i][j] = -3;
            else a[i][j] = c-'0';
        }
    }
    mx[0][0] = mn[0][0] = a[0][0];
    for(int i = 2; i < n; i += 2){
        mx[i][0] = mn[i][0] = operate(mx[i-2][0], a[i-1][0], a[i][0]);
        mx[0][i] = mn[0][i] = operate(mn[0][i-2], a[0][i-1], a[0][i]);
    }
    mx[1][1] = max(operate(mx[0][0], a[1][0], a[1][1]), operate(mx[0][0], a[0][1], a[1][1]));
    mn[1][1] = min(operate(mn[0][0], a[1][0], a[1][1]), operate(mn[0][0], a[0][1], a[1][1]));
    open(2, 2);
    if(n == 5){
        mx[3][1] = max(max(operate(mx[2][0], a[2][1], a[3][1]), operate(mx[2][0], a[3][0], a[3][1])), operate(mx[1][1], a[2][1], a[3][1]));
        mn[3][1] = min(min(operate(mn[2][0], a[2][1], a[3][1]), operate(mn[2][0], a[3][0], a[3][1])), operate(mn[1][1], a[2][1], a[3][1]));
        mx[1][3] = max(max(operate(mx[0][2], a[0][3], a[1][3]), operate(mx[0][2], a[1][2], a[1][3])), operate(mx[1][1], a[1][2], a[1][3]));
        mn[1][3] = min(min(operate(mn[0][2], a[0][3], a[1][3]), operate(mn[0][2], a[1][2], a[1][3])), operate(mn[1][1], a[1][2], a[1][3]));
        open(4, 2); open(3, 3); open(2, 4); open(4, 4);
        // for(int i = 0; i < 5; i++){
        //     for(int j = 0; j < 5; j++){
        //         cout << mx[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for(int i = 0; i < 5; i++){
        //     for(int j = 0; j < 5; j++){
        //         cout << mn[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        cout << mx[4][4] << ' ' << mn[4][4] << '\n';
        return 0;
    }
    cout << mx[2][2] << ' ' << mn[2][2] << '\n';
    return 0;
}

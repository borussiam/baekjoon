#include <bits/stdc++.h>

using namespace std;

int main()
{
    string N; cin >> N;
    int len = N.size();
    int a[len];
    for(int i = 0; i < len; i++) a[i] = N[i] - '0';
    sort(a, a+len, [](int a, int b){return a > b;});
    for(int i = 0; i < len; i++) cout << a[i];
    return 0;
}

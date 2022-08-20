#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,a[2001],save[4001]={0},m;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> m;
    for(int i=1;i<n;i++){
        for(int j=0;j<i&&j<=n-i&&a[i-j]==a[i+j];j++)
            save[2*i-1]++;
        for(int j=0;j<i&&j<=n-i&&a[i-j]==a[i+j+1];j++)
            save[2*i]++;
    }
    save[2*n-1]=1;
    while(m--){
        int i,f;
        cin >> i >> f;
        if(save[i+f-1]>(f-i)/2) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}

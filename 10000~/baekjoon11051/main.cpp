#include <iostream>
#define MOD 10007

using namespace std;

int comb[1005][1005];

int main()
{
    int n,k;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i) comb[i][j]=1;
            else comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
        }
    }
    cin >> n >> k;
    cout << comb[n][k] << endl;
    return 0;
}

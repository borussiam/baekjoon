#include <iostream>
#include <cstring>
#define INF 987654321

using namespace std;

int memo[100005];

int main()
{
    for(int i=0;i<100005;i++) memo[i]=INF;
    int cnt=1,n;
    cin >> n;
    while(cnt*cnt<=100005){
        if(cnt*cnt>n){
            cnt--;
            break;
        }
        memo[cnt*cnt]=1;
        cnt++;
    }
    for(int i=2;i<=n;i++){
        if(memo[i]==1) continue;
        for(int j=1;j<=cnt;j++){
            if(i-j*j<0) break;
            memo[i]=min(memo[i],memo[i-j*j]+1);
        }
    }
    cout << memo[n] << endl;
    return 0;
}

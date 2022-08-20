#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int two(int n)
{
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    if(n%2){
        return 2*two(n/2)*two(n/2);
    }
    return two(n/2)*two(n/2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, r, c;
    cin >> N >> r >> c;
    pair<int, int> quadrant[N-1];
    int quad[N];
    for(int i = N-1; i >= 0; i--){
        quadrant[N-i-1].first = (r%two(i+1)) / two(i);
        quadrant[N-i-1].second = (c%two(i+1)) / two(i);
    }
    int ans=0;
    for(int i = 0; i < N; i++){
        if(quadrant[i].first){
            if(quadrant[i].second){
                quad[i]=3;
            }
            else{
                quad[i]=2;
            }
        }
        else{
            if(quadrant[i].second){
                quad[i]=1;
            }
            else{
                quad[i]=0;
            }
        }
        ans += quad[i]*two(2*(N-i-1));
    }
    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> pq;
    int N; cin >> N;
    while(N--){
        int x; cin >> x;
        if(x){
            pq.push(x);
        }
        else{
            if(pq.empty()){
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
    return 0;
}

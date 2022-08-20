#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0, a; i < N; i++){
        cin >> a;
        pq.push(a);
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0, a; j < N; j++){
            cin >> a;
            pq.push(a);
        }
        for(int j = 0; j < N; j++){
            pq.pop();
        }
    }
    cout << pq.top() << '\n';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6;
bool visited[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        fill(visited, visited+MAX, 0);
        priority_queue<pii> pq_d;
        priority_queue<pii, vector<pii>, greater<pii> > pq_a;
        int k; cin >> k;
        for(int i = 0; i < k; i++){
            char ch;
            int n;
            cin >> ch >> n;
            if(ch=='I'){
                pq_d.push({n, i});
                pq_a.push({n, i});
            }
            else{
                if(n==1){
                    while(!pq_d.empty() && visited[pq_d.top().second]){
                        pq_d.pop();
                    }
                    if(pq_d.empty()){
                        continue;
                    }
                    visited[pq_d.top().second]=true;
                    pq_d.pop();
                }
                else{
                    while(!pq_a.empty() && visited[pq_a.top().second]){
                        pq_a.pop();
                    }
                    if(pq_a.empty()){
                        continue;
                    }
                    visited[pq_a.top().second]=true;
                    pq_a.pop();
                }
            }
        }
        while(!pq_d.empty() && visited[pq_d.top().second]){
            pq_d.pop();
        }
        while(!pq_a.empty() && visited[pq_a.top().second]){
            pq_a.pop();
        }
        if(pq_d.empty() && pq_a.empty()){
            cout << "EMPTY\n";
        }
        else{
            cout << pq_d.top().first << ' ' << pq_a.top().first << '\n';
        }
    }
    return 0;
}

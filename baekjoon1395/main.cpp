#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX_ST = 1<<18;
int N, M, start = MAX_ST / 2, seg[MAX_ST];
bool lazy[MAX_ST];

void propagate(int node, int ns, int ne)
{
    if(lazy[node]){
        if(node < start){
            lazy[node*2] ^= 1;
            lazy[node*2+1] ^= 1;
            int temp = 0;
            // 왼쪽 자식이 뒤집힐 예정이라면
            if(lazy[node*2]){
                // 왼쪽 자식 밑에 있는 leaf node 수 - 그 중 현재 켜져 있는 스위치 수
                temp += (ne - ns) / 2 - seg[node*2];
            }
            else{
                // 현재 켜져 있는 스위치 수
                temp += seg[node*2];
            }
            // 오른쪽 자식이 뒤집힐 예정이라면
            if(lazy[node*2+1]){
                temp += (ne - ns) / 2 - seg[node*2+1];
            }
            else{
                temp += seg[node*2+1];
            }
            // 값 갱신
            seg[node] = temp;
        }
        // leaf node라면 그냥 뒤집어 줌
        else{
            seg[node] ^= 1;
        }
        lazy[node] = false;
    }
}

void reverse(int s, int e, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s){
        return;
    }
    if(s <= ns && ne <= e){
        lazy[node] ^= 1;
        propagate(node, ns, ne);
        return;
    }
    int mid = (ns + ne) / 2;
    reverse(s, e, node*2, ns, mid);
    reverse(s, e, node*2+1, mid, ne);
    seg[node] = seg[node*2] + seg[node*2+1];
}

int sum(int s, int e, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s){
        return 0;
    }
    if(s <= ns && ne <= e){
        return seg[node];
    }
    int mid = (ns + ne) / 2;
    return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(seg, seg+MAX_ST, 0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int O, S, T;
        cin >> O >> S >> T;
        if(O == 0){
            reverse(S-1, T, 1, 0, start);
        }
        else{
            cout << sum(S-1, T, 1, 0, start) << '\n';
        }
        // for(int i = start; i < start+N; i++){
        //     cout << seg[i] << ' ';
        // }
        // cout << '\n';
    }
    return 0;
}

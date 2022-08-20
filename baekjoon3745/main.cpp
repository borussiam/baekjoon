#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, seg[400404], arr[100101], len;
vector<pii> srt;

int find_max(int L, int R, int curr, int nodeL, int nodeR)
{
    if(R < nodeL || nodeR < L){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return seg[curr];
    }
    int mid = (nodeL + nodeR) / 2;
    return max(find_max(L, R, curr*2, nodeL, mid), find_max(L, R, curr*2+1, mid+1, nodeR));
}

void update(int loc, int val)
{
    loc += len;
    seg[loc] = val;
    while(loc > 1){
        loc /= 2;
        seg[loc] = max(seg[loc*2], seg[loc*2+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n){
        if(!srt.empty()){
            srt.clear();
        }
        fill(arr, arr+n, 0);
        len = 1;
        while(n > len){
            len *= 2;
        }
        fill(seg, seg+len*2+1, 0);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            srt.push_back({arr[i], -i});
        }
        sort(srt.begin(), srt.end());
        for(int i = 0; i < n; i++){
            int val = find_max(0, -srt[i].second-1, 1, 0, len-1);
            update(-srt[i].second, val+1);
        }
        cout << seg[1] << '\n';
        // int pr = 1, cnt = 1;
        // while(pr != len*2){
        //     for(int i = 0; i < pr; i++){
        //         cout << seg[cnt] << ' ';
        //         ++cnt;
        //     }
        //     pr *= 2;
        //     cout << '\n';
        // }
    }
    return 0;
}

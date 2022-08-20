#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100000;
int inorder[MAX], postorder[MAX];
int in_idx[MAX], post_idx[MAX];

void pre(int in_start, int post_start, int len)
{
    if(len==0){
        return;
    }
    if(len==1){
        cout << postorder[post_start] << ' ';
        return;
    }
    cout << postorder[post_start+len-1] << ' ';
    int len_l = in_idx[postorder[post_start+len-1]]-in_start;
    pre(in_start, post_start, len_l);
    int len_r = len-len_l-1;
    pre(in_start+len_l+1, post_start+len_l, len_r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
        in_idx[inorder[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> postorder[i];
        post_idx[postorder[i]] = i;
    }
    pre(0, 0, n);
    return 0;
}

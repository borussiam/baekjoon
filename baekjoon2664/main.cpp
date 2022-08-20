#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pi;

int d, n, ans = 0;
vector<pi> po(51, make_pair(-1, -1)), ext(51, make_pair(-1, -1));
vector<int> sh(51);
queue<int> coord;

pi operator +(const pi& p, const pi& d){
    return make_pair(p.x + d.x, p.y + d.y);
}

int determine(int i)
{
    if(i == 0 || i == n) return 0;
    if(po[i - 1].x == po[i].x){
        if(po[i - 1].y > po[i].y){
            if(po[i].x < po[i + 1].x)
                return 0;
            return 5;
        }
        if(po[i].x < po[i + 1].x)
            return 7;
        return 2;
    }
    if(po[i - 1].x > po[i].x){
        if(po[i].y < po[i + 1].y)
            return 4;
        return 3;
    }
    if(po[i].y < po[i + 1].y)
        return 1;
    return 6;
}

int cross(int p)
{
    int xp1 = ext[p].x, xp2 = ext[p + 1].x, yp1 = ext[p].y, yp2 = ext[p + 1].y;
    int ret = -1;
    if(p == n - 1) return ret;
    bool vert = (yp1 == yp2);
    for(int i = p + 2; i < n; i++){
        int xi1 = ext[i].x, xi2 = ext[i + 1].x, yi1 = ext[i].y, yi2 = ext[i + 1].y;
        if(p == 0 && i == n - 1) break;
        if(yi1 == yi2){
            // 가로 가로
            if(vert){
                if(yp1 == yi1 && min(xp1, xp2) <= xi1 && xi1 <= max(xp1, xp2) && (xi2 >= max(xp1, xp2) || xi2 <= min(xp1, xp2))){
                    ret = i;
                    ext[p + 1] = make_pair(-1, -1);
                }
            }
            // 세로 가로
            else if((min(yp1, yp2) <= yi1 && yi1 <= max(yp1, yp2)) && min(xi1, xi2) <= xp1 && xp1 <= max(xi1, xi2)){
                ret = i;
                ext[p + 1] = make_pair(xp1, yi1);
            }
        }
        else{
            // 가로 세로
            if(vert){
                if((min(yi1, yi2) <= yp1 && yp1 <= max(yi1, yi2)) && min(xp1, xp2) <= xi1 && xi1 <= max(xp1, xp2)){
                    ret = i;
                    ext[p + 1] = make_pair(xi1, yp1);
                }
            }
            // 세로 세로
            else if(xp1 == xi1 && min(yp1, yp2) <= yi1 && yi1 <= max(yp1, yp2) && (yi2 >= max(yp1, yp2) || yi2 <= min(yp1, yp2))){
                ret = i;
                ext[p + 1] = make_pair(-1, -1);
            }
        }
    }
    if(ret != -1) cross(ret);
    for(int j = p + 2; j <= ret; j++){
        ext[j] = make_pair(-1, -1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> d >> n;
    for(int i = 0; i < n; i++)
        cin >> po[i].x >> po[i].y;
    po[n] = {po[0].x, po[0].y};
    for(int i = 0; i <= n; i++){
        sh[i] = determine(i);
        if(sh[i] == 0 || sh[i] == 6){
            ext[i] = po[i] + make_pair(-d, -d);
        }
        else if(sh[i] == 1 || sh[i] == 7){
            ext[i] = po[i] + make_pair(d, -d);
        }
        else if(sh[i] == 2 || sh[i] == 4){
            ext[i] = po[i] + make_pair(d, d);
        }
        else{
            ext[i] = po[i] + make_pair(-d, d);
        }
    }
//    for(int i=0;i<=n;i++) cout << i << ": " << ext[i].x << ' ' << ext[i].y << '\n';
//    cout << "\n\n";
    for(int i = 0; i < n; i++){
        int check = -1;
        if(ext[i] != make_pair(-1, -1))
            check = cross(i);
        if(check != -1) i = check;
//        cout << "After " << i << ": " << check << '\n';
//        for(int k=0;k<n;k++) cout << k << ": " << ext[k].x << ' ' << ext[k].y << '\n';
//        if(check == -1) continue;
//        for(int j = i + 2; j <= check; j++)
//            ext[j] = make_pair(-1, -1);
//        i = check;
//        cout << "Now " << i << ": " << check << '\n';
//        for(int k=0;k<n;k++) cout << k << ": " << ext[k].x << ' ' << ext[k].y << '\n';
    }
//    for(int i=0;i<n;i++) cout << i << ": " << ext[i].x << ' ' << ext[i].y << '\n';
    for(int i = 0; i < n; i++){
        if(ext[i] != make_pair(-1, -1)){
            ans++;
            coord.push(i);
        }
    }
    cout << ans << '\n';
    while(!coord.empty()){
        cout << ext[coord.front()].x << ' ' << ext[coord.front()].y << '\n';
        coord.pop();
    }
    return 0;
}

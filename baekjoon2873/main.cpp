#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int r,c,mn_r,mn_c;
string ans;

void odd()
{
    string A;
    if(r%2==1){
        for(int i=1;i<=r/2;i++){
            for(int j=1;j<c;j++){
                A.push_back('R');
            }
            A.push_back('D');
            for(int j=1;j<c;j++){
                A.push_back('L');
            }
            A.push_back('D');
        }
        for(int j=1;j<c;j++){
            A.push_back('R');
        }
    }
    else{
        for(int i=1;i<=c/2;i++){
            for(int j=1;j<r;j++){
                A.push_back('D');
            }
            A.push_back('R');
            for(int j=1;j<r;j++){
                A.push_back('U');
            }
            A.push_back('R');
        }
        for(int j=1;j<r;j++){
            A.push_back('D');
        }
    }
    ans+=A;
}

void shrink_r()
{
    string A;
    for(int j=1;j<c;j++){
        A.push_back('R');
    }
    A.push_back('D');
    for(int j=1;j<c;j++){
        A.push_back('L');
    }
    A.push_back('D');
    r-=2;
    mn_r-=2;
    ans+=A;
}

void shrink_c()
{
    string A;
    for(int j=1;j<r;j++){
        A.push_back('D');
    }
    A.push_back('R');
    for(int j=1;j<r;j++){
        A.push_back('U');
    }
    A.push_back('R');
    c-=2;
    mn_c-=2;
    ans+=A;
}

void avoid()
{
    string A;
    int rr=r,cc=c;
    if(mn_r==1){
        A+="D";
        while(rr-2>0){
            A+="RDLD";
            rr-=2;
        }
        rr=r;
        r=1;
        if(c>2){
            r=rr;
            A+="RR";
            for(int i=1;i<r;i++)
                A+="U";
            A+="R";
            c-=3;
        }
    }
    else{
        A+="R";
        while(cc-2>0){
            A+="DRUR";
            cc-=2;
        }
        cc=c;
        c=1;
        if(r>2){
            c=cc;
            A+="DD";
            for(int i=1;i<c;i++)
                A+="L";
            A+="D";
            r-=3;
        }
    }
    ans+=A;
}

int main()
{
    int x,mn=MAX;
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> x;
            if(x<mn&&(i!=r||j!=c)&&(i+j)%2){
                mn=x;
                mn_r=i;
                mn_c=j;
            }
        }
    }
    if(r==2&&c==2){
        if(mn_r==1){
            ans+="DR";
        }
        else{
            ans+="RD";
        }
        cout << ans << endl;
        return 0;
    }
    if(r%2||c%2){
        odd();
        cout << ans << "\n";
        return 0;
    }
    while(mn_r>2) shrink_r();
    while(mn_c>2) shrink_c();
    avoid();
    odd();
    cout << ans << endl;
    return 0;
}

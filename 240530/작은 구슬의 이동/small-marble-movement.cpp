#include <iostream>
using namespace std;
int main() {
    int n,t,r,c;
    char d;
    cin >>n>>t>>r>>c>>d;
    r--;
    c--;
    int now = r*n+c;
    int dxy[4]={1,-n,-1,n};
    int dir;
    if(d=='U')
        dir=1;
    else if(d=='D')
        dir=3;
    else if(d=='R')
        dir=0;
    else
        dir=2;
    while(t--){
        int next = now + dxy[dir];
        if(next <0 || next>=n*n || (abs(dxy[dir])==1 && now/n!=next/n)){
            dir+=2;
            dir%=4;
        }else
            now=next;
    }

    cout << now/n+1 << " " << now%n+1;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    string S;
    cin >> S;
    int dx[4] ={1,0,-1,0};
    int dy[4] ={0,-1,0,1};
    int dir = 3;
    int x=0,y=0;
    for(auto s:S){
        if(s=='L'){
            dir--;
            if(dir<0)
                dir==3;
        }else if(s=='R'){
            dir++;
            if(dir>3)
                dir==0;
        }else if(s=='F'){
            x+=dx[dir];
            y+=dy[dir];
        }
    }
    cout << x <<" " <<y;
    return 0;
}
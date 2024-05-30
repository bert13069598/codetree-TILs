#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m;
    cin >>n>>m;
    vector<vector<int>> map(n+2,vector<int>(m+2));
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int dir = 0;
    int x = 1, y = 1;
    map[x][y]=1;
    int cnt=n*m-1;
    while(cnt--){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(nx<1||nx>=n+1||ny<1||ny>=m+1||map[nx][ny]){
            dir = (dir+1) % 4;
            nx=x+dx[dir];
            ny=y+dy[dir];
        }
        map[nx][ny]=map[x][y]+1;
        x=nx;
        y=ny;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << map[i][j] <<" ";
        }cout <<"\n";
    }
    
    return 0;
}
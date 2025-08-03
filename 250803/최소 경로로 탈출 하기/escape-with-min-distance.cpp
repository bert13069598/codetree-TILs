#include <iostream>
#include <queue>

using namespace std;

int n, m;
int grid[100][100];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        if(x==n-1 && y==m-1)
            return grid[x][y];
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(grid[nx][ny]==1){
                grid[nx][ny]=grid[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout<<bfs(0,0)-1;
    return 0;
}

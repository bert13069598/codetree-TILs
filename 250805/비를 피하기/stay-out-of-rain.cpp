#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, h, m;
int grid[100][100];
int visit[100][100];
int tmp[100][100];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int bfs(int x, int y, int v[100][100]){
    v[x][y]=1;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        if(grid[x][y]==3)
            return v[x][y]-1;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<v[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";

        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx >=n || ny>=n)
                continue;
            if(v[nx][ny]==0){
                v[nx][ny]=v[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]==1)
                visit[i][j]=1;
            else
                visit[i][j]=0;
        }
    }
    int ans[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(grid[i][j]==2){
                memcpy(tmp, visit, sizeof(int) * 100 * 100);
                ans[i][j]=bfs(i,j,tmp);
            }
            else
                ans[i][j]=0;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}

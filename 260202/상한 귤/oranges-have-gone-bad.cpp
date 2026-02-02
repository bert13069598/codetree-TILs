#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, k;
int grid[100][100];
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

int main() {
    cin >> n >> k;

    queue<tuple<int,int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]==0){
                grid[i][j]=-1;
            }else if(grid[i][j]==1){
                grid[i][j]=-2;
            }else if(grid[i][j]==2){
                q.emplace(i,j,0);
                grid[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        auto [x,y,d]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if((unsigned)nx>=n || (unsigned)ny>=n)
                continue;
            if(grid[nx][ny]==-1)
                continue;
            if(grid[nx][ny]==-2 || grid[nx][ny]>d+1){
                grid[nx][ny]=d+1;
                q.emplace(nx,ny,d+1);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}

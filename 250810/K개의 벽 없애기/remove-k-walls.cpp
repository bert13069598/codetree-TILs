#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    priority_queue<tuple<int,int,int>> q;
    q.push(make_tuple(k,r1,c1));
    grid[r1][c1]=1;
    while(!q.empty()){
        int k=get<0>(q.top());
        int x=get<1>(q.top());
        int y=get<2>(q.top());
        if(x==r2 && y==c2){
            cout<<grid[x][y]-1;
            return 0;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n)
                continue;
            if(!(nx==r1 && ny==c1) && grid[nx][ny]==1 && k>0){
                grid[nx][ny]=grid[x][y]+1;
                q.push(make_tuple(k-1,nx,ny));
            }
            else if(grid[nx][ny]==0){
                grid[nx][ny]=grid[x][y]+1;
                q.push(make_tuple(k,nx,ny));
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
    }
    cout<<-1;

    return 0;
}


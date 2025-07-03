#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    int answer=k;
    queue<pair<int,int>> q;
    for(int i=0;i<k;i++){
        grid[r[i]-1][c[i]-1]=1;
        q.push({r[i]-1,c[i]-1});
    }
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    while(!q.empty()){
        auto xy=q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nx=xy.first+dx[i];
            int ny=xy.second+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n)
                continue;
            if(grid[nx][ny]==0){
                grid[nx][ny]=1;
                q.push({nx,ny});
                answer++;
            }
        }
    }
    cout<<answer;

    return 0;
}

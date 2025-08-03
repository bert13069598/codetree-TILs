#include <iostream>
#include <queue>

using namespace std;

int n, k, u, d;
int grid[8][8];
int visit[8][8];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    int cnt=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n)
                continue;
            if(visit[nx][ny]!=0 && 
               abs(grid[x][y]-grid[nx][ny])>=u && 
               abs(grid[x][y]-grid[nx][ny])<=d){
                visit[nx][ny]=0;
                q.push(make_pair(nx,ny));
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            visit[i][j]=1;
        }
    }

    priority_queue<int> pq;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=0){
                visit[i][j]=0;
                pq.push(bfs(i,j));
            }
        }
    }
    int answer=0;
    while(k--){
        answer+=pq.top();
        pq.pop();
    }
    cout<<answer;

    return 0;
}

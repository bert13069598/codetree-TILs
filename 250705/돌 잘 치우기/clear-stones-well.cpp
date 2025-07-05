#include <iostream>
#include <queue>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];

int bfs(int grid[100][100],int x,int y) {
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};
    queue<pair<int,int>> q;
    int visit[n][n];
    for(int i=0;i<n*n;i++) 
        visit[i/n][i%n]=0;
    for(int i=0;i<k;i++){
        q.push({r[i],c[i]});
        visit[r[i]][c[i]]=1;
    }
    int answer=k;
    while(true){
        int x=q.front().first;
        int y=q.front().second;
        if(q.empty()){
            // cout<<answer<<"\n";
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<n;j++){
            //         cout<<visit[i][j]<<" ";
            //     }
            //     cout<<"\n";
            // }
            // cout<<"\n";
            return answer;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n)
                continue;
            if(!grid[nx][ny]&&!visit[nx][ny]){
                visit[nx][ny]=1;
                answer++;
                q.push({nx,ny});
            }
        }
    }
}

int dfs(int grid[100][100],int x,int y,int d) {
    if(d==m){
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        return bfs(grid,x,y);
    }
    int dx[4]={0,1};
    int dy[4]={1,0};
    int answer=0;
    for(int i=0;i<2;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n)
            continue;
        if(grid[nx][ny]){
            grid[nx][ny]=0;
            answer=max(answer,dfs(grid,nx,ny,d+1));
            grid[nx][ny]=1;
        }
    }
    return answer;
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }
    int answer=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]){
                if(m){
                    grid[i][j]=0;
                    answer=max(answer,dfs(grid,i,j,1));
                    grid[i][j]=1;
                }
                else
                    answer=max(answer,bfs(grid,i,j));
            }
    cout<<answer;
    return 0;
}

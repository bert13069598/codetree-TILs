#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int grid[100][100];
int r, c;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    r--;
    c--;
    int dx[4]={1,0,0,-1};
    int dy[4]={0,1,-1,0};
    queue<pair<int,int>> q;

    pair<int,int> now{r,c};
    while(k>0){
        k--;
        q.push(now);
        priority_queue<vector<int>> pq;
        int x=now.first;
        int y=now.second;
        pq.push({grid[x][y],-x,-y});
        vector<vector<int>> visit(100,vector<int>(100,0));
        while(!q.empty()){
            auto xy=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=xy.first+dx[i];
                int ny=xy.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n)
                    continue;
                if(grid[nx][ny]<grid[x][y]&&visit[nx][ny]==0){
                    pq.push({grid[nx][ny],-nx,-ny});
                    visit[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        if(pq.size()==1)
            break;
        pq.pop();
        now=make_pair(-pq.top()[1],-pq.top()[2]);
    }
    cout<<now.first+1<<" "<<now.second+1;

    return 0;
}

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, k;
int grid[100][100];
int visit[100][100];
int r1, c1, r2, c2;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            visit[i][j]=grid[i][j];
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

    queue<tuple<int,int,int>> q;
    q.push(make_tuple(r1,c1,k));
    visit[r1][c1]=1;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int k=get<2>(q.front());
        if(x==r2 && y==c2){
            cout<<visit[x][y]-1;
            return 0;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n)
                continue;
            if(visit[nx][ny]==1 && k>0){
                k--;
                visit[nx][ny]=0;
            }
            if(visit[nx][ny]==0){
                visit[nx][ny]=visit[x][y]+1;
                q.push(make_tuple(nx,ny,k));
            }
        }
    }
    cout<<-1;

    return 0;
}

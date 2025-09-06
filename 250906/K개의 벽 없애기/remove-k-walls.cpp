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
            visit[i][j]=1e4;
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

    int answer=-1;

    priority_queue<tuple<int,int,int>> q;
    q.push(make_tuple(k,r1,c1));
    visit[r1][c1]=1;
    while(!q.empty()){
        int k=get<0>(q.top());
        int x=get<1>(q.top());
        int y=get<2>(q.top());
        if(x==r2 && y==c2){
            answer=visit[x][y]-1;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n)
                continue;
            if(visit[nx][ny]>visit[x][y]+1){
                if(grid[nx][ny]==1) {
                    if (k>0) {
                        visit[nx][ny]=visit[x][y]+1;
                        q.push(make_tuple(k-1,nx,ny));
                    }
                } else {
                    visit[nx][ny]=visit[x][y]+1;
                    q.push(make_tuple(k,nx,ny));
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<visit[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
    }
    cout<<answer;

    return 0;
}



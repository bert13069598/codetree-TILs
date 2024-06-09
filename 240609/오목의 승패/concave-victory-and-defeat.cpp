#include <iostream>
#include <vector>
using namespace std;

int dx[4]={0,1,1,-1};
int dy[4]={1,0,1,1};

int dfs(int n, int x, int y, vector<vector<int>> &map, int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx<0||ny<0||nx>=n||ny>=n)
        return 2;
    if(map[nx][ny]==map[x][y]){
        int k = dfs(n,nx,ny,map,dir);
        // cout <<k << "("<<x<<","<<y<<")";
        return k+1;
    }else 
        return 2;
}
int main() {
    int n=19;
    vector<vector<int>> map(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    
    int team;
    pair<int,int> xy;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]!=0){
                int x=i;
                int y=j;
                team=map[x][y];
                xy={x,y};
                // cout << x << " " << y << " " << map[x][y] << "\n";
                for(int k=0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    int px = x - dx[k];
                    int py = y - dy[k];
                    if(nx<0||ny<0||nx>=n||ny>=n)
                        continue;
                    if(px>=0&&py>=0&&px<n&&py<n && map[px][py]==map[x][y])
                        continue;
                    if(map[nx][ny]==map[x][y]){
                        int d = dfs(n,nx,ny,map,k);
                        if(d==5){
                            cout << team << "\n";
                            cout << xy.first + 1 << " " << xy.second + 1<<"\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << 0;
    return 0;
}
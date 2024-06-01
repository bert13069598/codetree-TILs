#include <iostream>
#include <vector>
#include <queue>
#define MAX 102

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int answer = 0;

void dfs(pair<int,int> now, vector<vector<int>> &map){
    int x = now.first;
    int y = now.second;
    if(map[x][y]==1){
        answer++;
        return;
    }

    map[x][y]=2;
    for(int i=0;i<4;i++){
        int nx= x+dx[i];
        int ny= y+dy[i];
        if(nx<0||ny<0||nx>=MAX||ny>=MAX)
            continue;
        if(map[nx][ny]!=2)
            dfs({nx,ny}, map);
    }
}

int main() {
    int n,r,c;
    cin>>n;
    vector<vector<int>> map(MAX, vector<int>(MAX, 0));
    for(int i=0;i<n;i++){
        cin >> r >> c;
        map[r][c]=1;
    }
    map[0][0]=2;
    dfs({0,0},map);
    cout << answer;
    return 0;
}
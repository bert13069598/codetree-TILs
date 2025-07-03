#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    queue<pair<int,int>> q;
    q.push({0,0});
    a[0][0]=0;
    bool answer=false;
    while(!q.empty()) {
        auto xy = q.front();
        q.pop();
        if(xy==make_pair(n-1,n-1)){
            answer=true;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=xy.first+dx[i];
            int ny=xy.second+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n)
                continue;
            if(a[nx][ny]){
                a[nx][ny]=0;
                q.push({nx,ny});
            }
        }
    }
    
    cout<<answer;

    return 0;
}

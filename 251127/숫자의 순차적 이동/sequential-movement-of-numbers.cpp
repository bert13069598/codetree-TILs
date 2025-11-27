#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    while(m--){
        for(int i=0;i<n*n;i++){
            int j=0;
            for(;j<n*n;j++)
                if(grid[j/n][j%n]==i+1)
                    break;
            int x=j/n;
            int y=j%n;
            int c=grid[x][y];
            int mx,my,mc=0;
            for(int j=0;j<8;j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if((unsigned)nx>=n||(unsigned)ny>=n)
                    continue;
                if(grid[nx][ny]>mc){
                    mx=nx;
                    my=ny;
                    mc=grid[nx][ny];
                }
            }
            grid[x][y]=mc;
            grid[mx][my]=c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

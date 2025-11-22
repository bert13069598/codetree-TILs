#include <iostream>

using namespace std;

int n;
int r,c;
char grid[101][101];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    cin >> n;
    cin >> r >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=0;
    int x=r-1;
    int y=c-1;
    while(true){
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int rx=x+dx[(i+1)%4];
            int ry=y+dy[(i+1)%4];
            // if((unsigned)nx>=n||(unsigned)ny>=n)
            //     continue;
            if(grid[rx][ry]!='#')
                continue;
            if(grid[nx][ny]=='#')
                continue;
            int nrx=nx+dx[(i+1)%4];
            int nry=ny+dy[(i+1)%4];
            if(grid[nrx][nry]=='.'){
                answer++;
                x=nrx;
                y=nry;
            }else{
                x=nx;
                y=ny;
            }
            answer++;
            break;
        }
        if((unsigned)x>=n||(unsigned)y>=n)
            break;
        if(x==r-1&&y==c-1){
            answer=-1;
            break;
        }
    }
    cout << answer;

    return 0;
}

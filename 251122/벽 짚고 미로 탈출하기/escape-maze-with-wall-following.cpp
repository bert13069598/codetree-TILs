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
    int dir=3;
    int tmp=3;
    while(true){
        for(int i=0;i<4;i++){
            dir=(dir+1)%4;
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            int rx=x+dx[(dir+1)%4];
            int ry=y+dy[(dir+1)%4];
            if(grid[rx][ry]!='#')
                continue;
            if(grid[nx][ny]=='#')
                continue;
            int nrx=nx+dx[(dir+1)%4];
            int nry=ny+dy[(dir+1)%4];
            if(grid[nrx][nry]=='.'){
                answer++;
                x=nrx;
                y=nry;
            }else{
                if(dir-1<0)
                    dir=3;
                else
                    dir--;
                x=nx;
                y=ny;
            }
            answer++;
            break;
        }
        if((unsigned)x>=n||(unsigned)y>=n)
            break;
        if(x==r-1&&y==c-1){
            if(dir==3||!tmp){
                answer=-1;
                break;
            }else
                tmp--;
                
        }
    }

    cout << answer;

    return 0;
}



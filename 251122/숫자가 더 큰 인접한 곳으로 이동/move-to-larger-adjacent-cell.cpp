#include <iostream>

using namespace std;

int n;
int r, c;
int a[100][100];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main() {
    cin >> n >> r >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int x=r-1;
    int y=c-1;
    int nx=x,ny=y;
    while(x==nx && y==ny){
        cout << a[x][y] << " ";
        for(int i=0;i<4;i++){
            nx=x+dx[i];
            ny=y+dy[i];
            if((unsigned)nx>=n||(unsigned)ny>=n)
                continue;
            if(a[nx][ny]>a[x][y]){
                x=nx;
                y=ny;
                break;
            }
        }
    }

    return 0;
}

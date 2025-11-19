#include <iostream>

using namespace std;

int n;
int grid[200][200];
int r, c;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    r--;
    c--;
    int m=grid[r][c];
    grid[r][c]=0;
    for(int i=0;i<4;i++){
        int x=r;
        int y=c;
        for(int j=0;j<m-1;j++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if((unsigned)nx>=n||(unsigned)ny>=n)
                break;
            grid[nx][ny]=0;
            x=nx;
            y=ny;
        }
    }

    for(int i=0;i<n;i++){
        int temp[n]{}, k=n-1;
        for(int j=n-1;j>=0;j--)
            if(grid[j][i])
                temp[k--]=grid[j][i];
        for(int j=n-1;j>=0;j--)
            grid[j][i]=temp[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        c--;

        int r;
        for(int j=0;j<n;j++){
            if(grid[j][c]>0){
                r=j;
                break;
            }
        }

        int d=grid[r][c];
        grid[r][c]=0;
        for(int j=0;j<4;j++){
            int x=r;
            int y=c;
            for(int k=0;k<d-1;k++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if((unsigned)nx>=n || (unsigned)ny>=n)
                    break;
                grid[nx][ny]=0;
                x=nx;
                y=ny;
            }         
        }

        for(int j=0;j<n;j++){
            int temp[n]{},l=0;
            for(int k=n-1;k>=0;k--)
                if(grid[k][j])
                    temp[l++]=grid[k][j];
            for(int k=n-1;k>=0;k--)
                grid[k][j]=temp[n-1-k];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

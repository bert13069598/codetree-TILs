#include <iostream>

using namespace std;

int n, m, t;
int a[20][20];
int v[20][20]{};
int r, c;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        r--;
        c--;
        v[r][c]=1;
    }
    while(t--){
        int nv[n][n]{};
        for(int i=0;i<n*n;i++){
            int x=i/n;
            int y=i%n;
            if(v[x][y]==1){
                int mx,my,mc=0;
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if((unsigned)nx>=n||(unsigned)ny>=n)
                        continue;
                    if(a[nx][ny]>mc){
                        mx=nx;
                        my=ny;
                        mc=a[nx][ny];
                    }
                }
                nv[mx][my]++;
            }
        }
        for(int i=0;i<n*n;i++)
            v[i/n][i%n]=nv[i/n][i%n]==1;
    }

    int answer=0;
    for(int i=0;i<n*n;i++)
        answer+=v[i/n][i%n];

    cout<<answer;

    return 0;
}

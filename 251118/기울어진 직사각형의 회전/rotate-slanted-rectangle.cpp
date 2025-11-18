#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;

int dx[4]={-1,-1,1,1};
int dy[4]={1,-1,-1,1};

int i0[4]={1,0,3,2};
int i1[4]={0,1,2,3};


int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    int x=r-1;
    int y=c-1;
    int temp=grid[x][y];
    int i=0;
    int nx,ny;
    if(dir){
        for(auto m:{m1,m2,m3,m4}){
            while(m--){
                nx=x+dx[i1[i]];
                ny=y+dy[i1[i]];

                // cout << x << " " << y << " " << nx << " " << ny << "\n"; 
                grid[x][y]=grid[nx][ny];
                if(!(i==3 && m==0)){
                    x=nx;
                    y=ny;
                }
            }
            i++;
        }
    }else{
        for(auto m:{m4,m3,m2,m1}){
            while(m--){
                nx=x+dx[i0[i]];
                ny=y+dy[i0[i]];

                // cout << x << " " << y << " " << nx << " " << ny << "\n"; 
                grid[x][y]=grid[nx][ny];
                if(!(i==3 && m==0)){
                    x=nx;
                    y=ny;
                }
            }
            i++;
        }
    }
    
    // cout << x << " " << y << " " << temp << "\n";
    grid[x][y]=temp;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

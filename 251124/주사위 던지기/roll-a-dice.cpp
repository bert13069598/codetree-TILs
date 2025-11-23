#include <iostream>

using namespace std;
#define W 0
#define N 1
#define B 2

int n, m;
int r, c;
char dir;
char dirs[4]={'L','R','U','D'};

int grid[100][100]{};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int dice[3] = {4, 5, 6};  // W:0 N:1 B:2

int main() {
    cin >> n >> m >> r >> c;
    int x=r-1;
    int y=c-1;

    grid[x][y]=dice[B];
    for (int i = 0; i < m; i++) {
        cin >> dir;
        int nx,ny;
        for(int j=0;j<4;j++){
            if(dir==dirs[j]){
                nx=x+dx[j];
                ny=y+dy[j];
                break;
            }
        }
        if((unsigned)nx>=n||(unsigned)ny>=n)
            continue;
        if(dir=='L'){
            int temp=dice[W];
            dice[W]=7-dice[B];
            dice[B]=temp;
        }else if(dir=='R'){
            int temp=7-dice[W];
            dice[W]=dice[B];
            dice[B]=temp;
        }else if(dir=='U'){
            int temp=dice[N];
            dice[N]=7-dice[B];
            dice[B]=temp;
        }else if(dir=='D'){
            int temp=7-dice[N];
            dice[N]=dice[B];
            dice[B]=temp;
        }
        grid[nx][ny]=dice[B];
        x=nx;
        y=ny;
    }

    // for(int i=0;i<n*n;i++){
    //     cout<<grid[i/n][i%n]<<" ";
    //     if(i%n==n-1)
    //         cout<<"\n";
    // }

    int answer=0;
    for(int i=0;i<n*n;i++)
        answer+=grid[i/n][i%n];
    cout<<answer;

    return 0;
}

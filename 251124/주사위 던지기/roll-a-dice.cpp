#include <iostream>
#include <map>

using namespace std;

int n, m;
int r, c;
char dir;
char dirs[4]={'L','R','U','D'};

int grid[100][100]{};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
map<char,int> dice={{'w',4},{'n',5},{'b',6}};

int main() {
    cin >> n >> m >> r >> c;
    int x=r-1;
    int y=c-1;

    grid[x][y]=dice['b'];
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
            int temp=dice['w'];
            dice['w']=7-dice['b'];
            dice['b']=temp;
        }else if(dir=='R'){
            int temp=7-dice['w'];
            dice['w']=dice['b'];
            dice['b']=temp;
        }else if(dir=='U'){
            int temp=dice['n'];
            dice['n']=7-dice['b'];
            dice['b']=temp;
        }else if(dir=='D'){
            int temp=7-dice['n'];
            dice['n']=dice['b'];
            dice['b']=temp;
        }
        grid[nx][ny]=dice['b'];
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

#include <iostream>

using namespace std;

int n;
int grid[100][100];

int dx[4]={0,1,0,-1};  // R D L U
int dy[4]={1,0,-1,0};

int game(int x,int y,int d){
    int t=1;
    while(true){
        t++;
        int nx=x+dx[d];
        int ny=y+dy[d];
        if((unsigned)nx>=n||(unsigned)ny>=n)
            break;
        if(grid[nx][ny]==1){
            if(d==1||d==3)
                d=(d+1)%4;
            else{
                if(d==0)
                    d=3;
                else
                    d--;
            }
        }else if(grid[nx][ny]==2){
            if(d==0||d==2)
                d=(d+1)%4;
            else{
                if(d==0)
                    d=3;
                else
                    d--;
            }
        }
        x=nx;
        y=ny;
    }
    return t;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int answer=0;
    for(int j=0;j<n;j++){
        answer=max(answer,game(0,j,1));
        answer=max(answer,game(n-1,j,3));
        answer=max(answer,game(j,0,0));
        answer=max(answer,game(j,n-1,2));
    }
    cout<<answer;
    return 0;
}

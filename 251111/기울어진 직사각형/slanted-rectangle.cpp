#include <iostream>

using namespace std;

int n;
int grid[20][20];

int dx[4]={-1,-1,1,1};
int dy[4]={1,-1,-1,1};

int tour(int x,int y,int s,int e,int visit[20][20]) {
    int sum=0;
    int i=x;
    int j=y;
    for(int t=0;t<4;t++){
        while(true){
            int nx=x+dx[t];
            int ny=y+dy[t];
            if(nx<i-(e-s)||nx>i||ny<s||ny>e)
                break;
            visit[nx][ny]=1;
            sum+=grid[nx][ny];
            x=nx;
            y=ny;
        }
    }
    return sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=0;
    for(int i=2;i<n;i++)
        for(int j=1;j<n-1;j++)
            for(int s2=0;s2<j;s2++)
                for(int e2=j+1;e2<n;e2++){
                    if(e2-s2>i)
                        continue;
                    int visit[20][20]{};
                    answer=max(answer,tour(i,j,s2,e2,visit));
                    // for(int tx=0;tx<n;tx++){
                    //     for(int ty=0;ty<n;ty++){
                    //         cout<<visit[tx][ty]<<" ";
                    //     }cout<<"\n";
                    // }cout<<"\n";
                }
    cout<<answer;

    return 0;
}

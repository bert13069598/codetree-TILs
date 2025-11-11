#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

int dfs(int k,int x,int y,int grid[20][20],int visit[20][20]){
    if(k==1){
        visit[x][y]=k;
        return grid[x][y];
    }
    int sum=0;
    if(!visit[x][y])
        sum=grid[x][y];
    visit[x][y]=k;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if((unsigned)nx>=n||(unsigned)ny>=n)
            continue;
        if(visit[nx][ny]<visit[x][y]-1){
            sum+=dfs(k-1,nx,ny,grid,visit);
        }
    }
    return sum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=0;
    for(int k=0;k<n;k++){
        int cost=2*k*k+2*k+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int visit[20][20]{};
                int sum=dfs(k+1,i,j,grid,visit);
                // if(sum==5){
                // if(sum==3 && sum*m-cost>=0){
                //     for(int i=0;i<n;i++){
                //         for(int j=0;j<n;j++)
                //             cout<<visit[i][j]<<" ";
                //         cout<<"\n";
                //     }
                //     cout<<sum<<" "<<sum*m<<" "<<k<<" "<<cost<<"\n\n";
                // }
                if(sum*m-cost>=0)
                    answer=max(answer,sum);
            }
        }
        
    }

    cout<<answer;

    return 0;
}


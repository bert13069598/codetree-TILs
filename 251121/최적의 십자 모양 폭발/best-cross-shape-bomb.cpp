#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[50][50];
int grid[50][50];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bomb(int i,int j){
    memcpy(grid,a,sizeof(a));
    int c=grid[i][j];
    grid[i][j]=0;

    for(int s=0;s<4;s++){
        int x=i;
        int y=j;
        for(int t=0;t<c-1;t++){
            int nx=x+dx[s];
            int ny=y+dy[s];
            if((unsigned)nx>=n||(unsigned)ny>=n)
                break;
            grid[nx][ny]=0;
            x=nx;
            y=ny;
        }
    }

    for(int s=0;s<n;s++){
        int temp[n]{},k=0;
        for(int t=n-1;t>=0;t--)
            if(grid[t][s]>0)
                temp[k++]=grid[t][s];
        for(int t=0;t<n;t++)
            grid[t][s]=temp[n-1-t];
    }

    int sum=0;
    for(int s=0;s<n-1;s++){
        for(int t=0;t<n-1;t++){
            if(grid[s][t]>0 && grid[s][t]==grid[s][t+1])
                sum++;
            if(grid[t][s]>0 && grid[t][s]==grid[t+1][s])
                sum++;
        }
    }
    for(int s=0;s<n-1;s++){
        if(grid[n-1][s]>0 && grid[n-1][s]==grid[n-1][s+1])
            sum++;
        if(grid[s][n-1]>0 && grid[s][n-1]==grid[s+1][n-1])
            sum++;
    }

    return sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int answer=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            answer=max(answer, bomb(i,j));
    
    cout<<answer;
    return 0;
}

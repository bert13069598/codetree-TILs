#include <iostream>

using namespace std;

int n;
int grid[20][20];
int visit[20][20]{};

int dx1[4]={-2,-1,1,2};
int dx2[4]={0,1,0,-1};
int dy2[4]={1,0,-1,0};
int dx3[4]={1,1,-1,-1};
int dy3[4]={1,-1,1,-1};

int dfs(int d,int bomb){
    if (d==0){
        int sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(visit[i][j])
                    sum++;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<visit[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";

        return sum;
    }
    int answer=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j]==1){
                grid[i][j]=0;
                visit[i][j]++;
                // cout<<d<<"("<<i<<","<<j<<")"<<bomb<<"\n";
                if(bomb==1){
                    for(int k=0;k<4;k++){
                        int nx=i+dx1[k];
                        if((unsigned)nx>=n)
                            continue;
                        visit[nx][j]++;
                    }
                }
                if(bomb==2){
                    for(int k=0;k<4;k++){
                        int nx=i+dx2[k];
                        int ny=j+dy2[k];
                        if((unsigned)nx>=n||(unsigned)ny>=n)
                            continue;
                        visit[nx][ny]++;
                    }
                }
                if(bomb==3){
                    for(int k=0;k<4;k++){
                        int nx=i+dx3[k];
                        int ny=j+dy3[k];
                        if((unsigned)nx>=n||(unsigned)ny>=n)
                            continue;
                        visit[nx][ny]++;
                    }
                }
                if(d-1>0){
                    answer=max(max(dfs(d-1,1),dfs(d-1,2)),dfs(d-1,3));
                }else{
                    answer=dfs(d-1,0);
                }

                grid[i][j]=1;
                visit[i][j]--;
                if(bomb==1){
                    for(int k=0;k<4;k++){
                        int nx=i+dx1[k];
                        if((unsigned)nx>=n)
                            continue;
                        visit[nx][j]--;
                    }
                }
                if(bomb==2){
                    for(int k=0;k<4;k++){
                        int nx=i+dx2[k];
                        int ny=j+dy2[k];
                        if((unsigned)nx>=n||(unsigned)ny>=n)
                            continue;
                        visit[nx][ny]--;
                    }
                }
                if(bomb==3){
                    for(int k=0;k<4;k++){
                        int nx=i+dx3[k];
                        int ny=j+dy3[k];
                        if((unsigned)nx>=n||(unsigned)ny>=n)
                            continue;
                        visit[nx][ny]--;
                    }
                }
                return answer;
            }
        }
    }
}

int main() {
    cin >> n;

    int d=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            d+=grid[i][j];
        }
    }

    cout<<max(max(dfs(d,1),dfs(d,2)),dfs(d,3));

    return 0;
}

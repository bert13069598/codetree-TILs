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
    int bomb1=0,bomb2=0,bomb3=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j]==1){
                grid[i][j]=0;
                visit[i][j]++;
                // cout<<d<<" "<<bomb<<"\n";
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

                bomb1=dfs(d-1,1);
                bomb2=dfs(d-1,2);
                bomb3=dfs(d-1,3);

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
            }
        }
    }
    return max(max(bomb1,bomb2),bomb3);
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

    int answer=0;
    answer=max(answer,dfs(d,1));
    answer=max(answer,dfs(d,2));
    answer=max(answer,dfs(d,3));
    cout<<answer;

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int a[200][200];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void find_water(int a[200][200],queue<pair<int,int>> &water,int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M)
                continue;
            if(a[nx][ny]==0){
                a[nx][ny]=2;
                q.push({nx,ny});
                water.push({nx,ny});
            }
        }
    }
}

void melt_ice(int a[200][200],queue<pair<int,int>> &water){
    queue<pair<int,int>> q;
    while(!water.empty()){
        q.push(water.front());
        water.pop();
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M)
                continue;
            if(a[nx][ny]==1){
                a[nx][ny]=2;
                water.push({nx,ny});
                find_water(a,water,nx,ny);
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int,int>> q;
    a[0][0]=2;
    find_water(a,q,0,0);
    // for (int i=0;i<N;i++){
    //     for (int j=0;j<M;j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<"\n";
    // }cout<<"\n";

    int ans1=0,ans2;
    while(!q.empty()){
        melt_ice(a,q);
        if(q.empty())
            break;
        ans1++;
        ans2=q.size();
        // for (int i=0;i<N;i++){
        //     for (int j=0;j<M;j++){
        //         cout<<a[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n\n";
    }
    cout <<ans1<<" "<<ans2;

    return 0;
}

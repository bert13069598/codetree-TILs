#include <iostream>
#include <deque>

using namespace std;

int n, M, K;
int map[10000][10000]{};
char d;
int p;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
char dirs[4]={'U','D','R','L'};

int main() {
    cin >> n >> M >> K;

    for (int i = 0; i < M; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        map[x][y]=1;
    }

    int answer=0;
    int x=0,y=0;
    deque<pair<int,int>> dq;
    dq.emplace_back(x,y);
    map[x][y]=2;
    for (int i = 0; i < K; i++){
        cin >> d >> p;
        int j=0;
        for(;j<4;j++)
            if(d==dirs[j])
                break;
        while(p--){
            answer++;
            auto [x,y]=dq.front();

            int nx=x+dx[j];
            int ny=y+dy[j];
            if((unsigned)nx>=n||(unsigned)ny>=n){
                cout<<answer;
                return 0;
            }
            if(map[nx][ny]==0){
                auto [bx,by]=dq.back();
                dq.pop_back();
                map[bx][by]=0;
            }else if(map[nx][ny]==1){
            }else if(map[nx][ny]==2){
                cout<<answer;
                return 0;
            }
            map[nx][ny]=2;
            dq.emplace_front(nx,ny);
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<n;j++){
            //         cout<<map[i][j]<<" ";
            //     }cout<<"\n";
            // }cout<<"\n";
        }
    }  
    cout<<answer;

    return 0;
}

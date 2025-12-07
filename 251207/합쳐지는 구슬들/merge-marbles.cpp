#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n, m, t;
int r,c;
char d[2500];
int w[2500];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char dirs[4]={'D','R','U','L'};

int main() {
    cin >> n >> m >> t;

    queue<tuple<int,int,int>> now;
    for (int i = 0; i < m; i++) {
        cin >> r>>c >> d[i] >> w[i];
        r--;
        c--;
        now.emplace(r,c,i);
    }
    for(int i=0;i<t;i++){
        map<pair<int,int>,priority_queue<int>> next;
        while(!now.empty()){
            auto [x,y,p]=now.front();
            now.pop();
            int k;
            if(d[p]=='U')
                k=2;
            else if(d[p]=='D')
                k=0;
            else if(d[p]=='L')
                k=3;
            else if(d[p]=='R')
                k=1;
            int nx=x+dx[k];
            int ny=y+dy[k];
            if((unsigned)nx>=n||(unsigned)ny>=n){
                d[p]=dirs[(k+2)%4];
                next[{x,y}].emplace(-p);
            }else{
                next[{nx,ny}].emplace(-p);
            }
        }
        for(auto& [k,v]:next){
            int sum=0;
            int p=-v.top();
            while(!v.empty()){
                sum+=w[-v.top()];
                v.pop();
            }
            w[p]=sum;
            now.emplace(k.first,k.second,p);
        }
    }
    cout<<now.size()<<" ";
    int maxw=0;
    while(!now.empty()){
        auto [x,y,p]=now.front();
        maxw=max(maxw,w[p]);
        now.pop();
    }
    cout<<maxw;

    

    return 0;
}

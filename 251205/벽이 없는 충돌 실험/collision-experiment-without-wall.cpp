#include <iostream>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int T;
int N;
int x,y,w;
char d[100];

// R D L U
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        int minx=1000,miny=1000,maxx=-1000,maxy=-1000;
        queue<tuple<int,int,int,char>> now;
        for (int i = 0; i < N; i++) {
            cin >> x>>y>>w >> d[i];
            x*=2;
            y*=2;
            minx=min(minx,x);
            miny=min(miny,y);
            maxx=max(maxx,x);
            maxy=max(maxy,y);
            now.emplace(x,y,w,i);
        }

        int answer=-1;
        for(int i=0;i<max(maxx-minx,maxy-miny);i++){
            map<pair<int,int>,priority_queue<tuple<int,int>>> next;
            while(!now.empty()){
                auto [x,y,w,p]=now.front();
                now.pop();
                int k;
                if(d[p]=='U')
                    k=0;
                else if(d[p]=='R')
                    k=1;
                else if(d[p]=='D')
                    k=2;
                else if(d[p]=='L')
                    k=3;
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>maxx||ny>maxy||nx<minx||ny<miny)
                    continue;
                next[{nx,ny}].emplace(-w,-p);
            }
            for(auto& [xy, pq]:next){
                if(pq.size()>1)
                    answer=i+1;
                while(!pq.empty()){
                    if(pq.size()==1){
                        auto [x,y]=xy;
                        auto [w,p]=pq.top();
                        now.emplace(x,y,-w,-p);
                    }
                    pq.pop();
                }
            }
        }
        cout<<answer<<"\n";
    }

    return 0;
}
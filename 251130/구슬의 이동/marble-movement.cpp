#include <iostream>
#include <queue>

using namespace std;

int n, m, t, k;
int r, c;
char d[50*50];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char dirs[4]={'D','R','U','L'};
enum {D,R,U,L};
int v;

priority_queue<pair<int,int>> pq[50][50];  // now

int main() {
    cin >> n >> m >> t >> k;

    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d[i] >> v;
        r--;
        c--;
        pq[r][c].emplace(-v,-i);
    }

    while(t--){
        priority_queue<pair<int,int>> nv[n][n];  // next
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                while(pq[i][j].size()>0){
                    auto [v,p]=pq[i][j].top();
                    v=-v;
                    p=-p;
                    pq[i][j].pop();
                    int k=0;
                    for(;k<4;k++)
                        if(d[p]==dirs[k])
                            break;
                    int x=i,y=j,nx,ny;
                    for(int l=0;l<v;l++){
                        cout<<" "<<x<<" "<<y<<"\n";'
                        nx=x+dx[k];
                        ny=y+dy[k];
                        if((unsigned)nx>=n||(unsigned)nx>=n){
                            k=(k+2)%4;
                            nx=x+dx[k];
                            ny=y+dy[k];
                        }
                        x=nx;
                        y=ny;
                    }
                    d[p]=dirs[k];
                    cout<<"("<<p+1<<","<<dirs[k]<<")"<<i<<" "<<j<<"->";
                    cout<<nx<<" "<<ny<<endl;
                    nv[nx][ny].emplace(-v,-p);
                }
            }
        }
        // cout<<"\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                while(nv[i][j].size()>0){
                    if(nv[i][j].size()<=k)
                        pq[i][j].emplace(nv[i][j].top());
                    nv[i][j].pop();                    
                }
            }
        }
    }

    int answer=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            answer+=pq[i][j].size();
    cout<<answer;

    return 0;
}

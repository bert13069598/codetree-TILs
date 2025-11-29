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

priority_queue<pair<int,int>> pq[50][50];

int main() {
    cin >> n >> m >> t >> k;

    int va[n][n]{};  // valid
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d[i] >> v;
        r--;
        c--;
        va[r][c]++;
        pq[r][c].emplace(-v,-i);
    }

    while(t--){
        int nv[n][n]{};  // next for valid
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                while(va[i][j]>0){
                    auto [v,p]=pq[i][j].top();
                    v=-v;
                    p=-p;
                    va[i][j]--;
                    pq[i][j].pop();
                    int k=0;
                    for(;k<4;k++)
                        if(d[p]==dirs[k])
                            break;
                    int nx=i+dx[k]*v;
                    int ny=j+dy[k]*v;
                    if(k==U)
                        nx=n-1-nx;
                    else if(k==L)
                        ny=n-1-ny;
                    // cout<<"("<<p+1<<","<<v<<")"<<i<<" "<<j<<"->";
                    // cout<<nx<<" "<<ny<<"->";
                    int quo,rem;
                    if(k==D||k==U){
                        quo=nx/(n-1);
                        rem=nx%(n-1);
                    }else{
                        quo=ny/(n-1);
                        rem=ny%(n-1);
                    }
                    if((k==U||k==L) != quo%2){ // !xor
                        rem=n-1-rem;
                        d[p]=dirs[(k+2)%4];
                    }
                    if(k==D||k==U)
                        nx=rem;
                    else
                        ny=rem;
                    // cout<<nx<<" "<<ny<<endl;
                    nv[nx][ny]++;
                    pq[nx][ny].emplace(-v,-p);
                }
            }
        }
        // cout<<"\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                while(nv[i][j]>k){
                    nv[i][j]--;
                    pq[i][j].pop();
                }
                va[i][j]=nv[i][j];
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


#include <iostream>
#include <queue>

using namespace std;

int n, m, t, k;
int r, c;
char d[50*50];
int dx[2]={1,0};
int dy[2]={0,1};
char dirs[4]={'D','R','U','L'};
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
        pq[r][c].emplace(v,i);
    }

    while(t--){
        int nv[n][n]{};  // next for valid
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                while(va[i][j]>0){
                    auto [v,p]=pq[i][j].top();
                    va[i][j]--;
                    pq[i][j].pop();
                    int k=0;
                    for(;k<4;k++)
                        if(d[p]==dirs[k])
                            break;
                    if(k==2||k==3){
                        v=n-v%n;
                        k%=2;
                    }
                    int nx=i+dx[k]*v;
                    int ny=j+dy[k]*v;
                    if(nx>=n||ny>=n){
                        int quo,rem;
                        if(k==0){  // D
                            quo=(i+v)/(n-1);
                            rem=(i+v)%(n-1);
                            if(quo%2)
                                nx=n-1-rem;
                            else
                                nx=rem;
                        }else{  // R
                            quo=(j+v)/(n-1);
                            rem=(j+v)%(n-1);
                            if(quo%2)
                                ny=n-1-rem;
                            else
                                ny=rem;
                        }
                        if(quo%2)
                            d[p]=(k+2)%4;
                    }
                    nv[nx][ny]++;
                    pq[nx][ny].emplace(v,p);
                }
            }
        }
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

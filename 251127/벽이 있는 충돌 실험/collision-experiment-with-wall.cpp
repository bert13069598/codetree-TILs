#include <iostream>

using namespace std;

int T;
int n, m;
int x,y;
char d;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char dirs[4]={'R','D','L','U'};

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        int va[n][n]{};  // valid a
        int da[n][n]{};  // direction a

        for (int i = 0; i < m; i++) {
            cin >> x >> y >> d;
            x--;
            y--;
            int j=0;
            for(;j<4;j++)
                if(d==dirs[j])
                    break;
            va[x][y]=1;
            da[x][y]=j;
        }

        int answer=0;
        int tmp=2*n;
        while(tmp--){
            int nv[n][n]{};  // next for va
            int nd[n][n]{};  // next for da
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(va[i][j]){
                        int x=i;
                        int y=j;
                        int dir=da[x][y];
                        int nx=x+dx[dir];
                        int ny=y+dy[dir];
                        if((unsigned)nx>=n||(unsigned)ny>=n){
                            nd[x][y]=(dir+2)%4;
                            nv[x][y]++;
                        }else{
                            nd[nx][ny]=da[x][y]; // overwrite..
                            nv[nx][ny]++;
                        }
                    }
                }
            }
            // for(int i=0;i<n*n;i++){
            //     cout<<na[i/n][i%n]<<" ";
            //     if(i%n==n-1)
            //         cout<<"\n";
            // }cout<<"\n";
            // for(int i=0;i<n*n;i++){
            //     cout<<da[i/n][i%n]<<" ";
            //     if(i%n==n-1)
            //         cout<<"\n";
            // }cout<<"\n";cout<<"===\n";

            for(int i=0;i<n*n;i++){
                int x=i/n;
                int y=i%n;
                if(nv[x][y]==1){
                    va[x][y]=nv[x][y];
                    da[x][y]=nd[x][y];
                }else{
                    va[x][y]=0;
                }
            }
            int sum=0;
            for(int i=0;i<n*n;i++)
                sum+=va[i/n][i%n];
            answer=sum;
        }
        cout<<answer<<"\n";
    }

    return 0;
}

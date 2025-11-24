#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int a[100][100]{};
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
vector<pair<int,int>> st;

int main() {
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    int x=r-1;
    int y=c-1;
    st.push_back({x,y});
    for(int i=0;i<m;i++){
        int num=st.size();
        for(int k=0;k<num;k++){
            auto [x,y]=st[k];
            a[x][y]=1;
            for(int j=0;j<4;j++){
                int nx=x+dx[j]*pow(2,i);
                int ny=y+dy[j]*pow(2,i);
                if((unsigned)nx>=n||(unsigned)ny>=n)
                    continue;
                if(a[nx][ny]==0){
                    a[nx][ny]=1;
                    st.push_back({nx,ny});
                }
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<"\n";
    // }

    int answer=0;
    for(int i=0;i<n*n;i++)
        answer+=a[i/n][i%n];
    cout<<answer;

    return 0;
}
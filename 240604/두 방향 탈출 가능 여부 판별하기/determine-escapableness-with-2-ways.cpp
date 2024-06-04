#include <iostream>
using namespace std;
bool goal=false;
void dfs(int n,int m,int now, int*map){
    if(now==n*m-1)
        goal=true;
    int dxy[2]={1,m};
    for(int i=0;i<2;i++){
        int next =now+dxy[i];
        if(next>=n*m)
            continue;
        if(dxy[i]==1&&next/m!=now/m)
            continue;
        if(map[next]==1){
            map[next]=0;
            dfs(n,m,next,map);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    int map[n*m];
    for(int i=0;i<n*m;i++)
        cin>>map[i];
    map[0]=0;
    dfs(n,m,0,map);
    cout << goal;
    return 0;
}
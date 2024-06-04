#include <iostream>
using namespace std;
bool goal=false;
void dfs(int n,int now, int*map){
    if(now==n*n-1){
        goal=true;
    }
    int dxy[4]={1,-1,n,-n};
    for(int i=0;i<4;i++){
        int next =now=dxy[i];
        if(next<0||next>=n)
            continue;
        if(abs(dxy[i])==1&&next/n!=now/n)
            continue;
        if(!map[next]){
            map[next]=1;
            dfs(n,next,map);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    int map[n*n];
    for(int i=0;i<n*n;i++)
        cin>>map[i];
    map[0]=1;
    dfs(n,0,map);
    cout << goal;
    return 0;
}
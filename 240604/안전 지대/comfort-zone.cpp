#include <iostream>
#include <vector>
using namespace std;
void dfs(int n,int m,int k, int now, int *map, vector<bool> &visit){
    int dxy[4]={1,-1,m,-m};
    for(int i=0;i<4;i++){
        int next = now + dxy[i];
        if(next<0||next>=n*m)
            continue;
        if(abs(dxy[i])==1&&now/m!=next/m)
            continue;
        if(map[next]>k&&!visit[next]){
            visit[next]=true;
            dfs(n,m,k,next,map,visit);
        }
    }
}

int main() {
    int n,m,k=0;
    cin>>n>>m;
    int map[n*m];
    for(int i=0;i<n*m;i++){
        cin>>map[i];
        if(map[i]>k)
            k=map[i];
    }
    vector<int> safe;
    for(int i=1;i<=k;i++){
        vector<bool> visit(n*m,false);
        int sum=0;
        for(int j=0;j<n*m;j++){
            if(map[j]>i && !visit[j]){
                sum++;
                visit[j]=true;
                dfs(n,m,i,j,map,visit);
            }
        }
        safe.push_back(sum);
    }
    // for(int i=0;i<k;i++)
    //     cout << safe[i] << " ";
    // cout << "\n";

    int tmp=0;
    pair<int,int> answer;
    for(int i=k-1;i>=0;i--){
        if(safe[i]>=tmp){
            tmp=safe[i];
            answer={i+1,safe[i]};
        }
    }
    cout << answer.first << " " << answer.second;
    return 0;
}
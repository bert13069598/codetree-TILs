#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n,m,s,e,w,a,b;
    cin>>n>>m;
    vector<map<int,int>> graph(n+1);
    for(int i=0;i<m;i++){
        cin>>s>>e>>w;
        graph[s][e]=w;
        graph[e][s]=w;
    }
    cin>>a>>b;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.emplace(0,b);
    vector<int> visit(n+1,1e8);
    visit[b]=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &[key,value]:graph[node]){
            int ncost=value+cost;
            int nnode=key;
            if(ncost<visit[nnode]){
                visit[nnode]=ncost;
                pq.emplace(ncost,nnode);
            }
        }
    }
    cout<<visit[a]<<"\n";
    cout<<a<<" ";
    int x=a;
    while(x!=b){
        for(int i=1;i<=n;i++){
            if(!graph[i][x])
                continue;
            if(visit[i]+graph[i][x]==visit[x]){
                x=i;
                break;
            }
        }
        cout<<x<<" ";
    }
    return 0;
}
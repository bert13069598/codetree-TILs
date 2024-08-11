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
        if(graph[s][e])
            w=min(w,graph[s][e]);
        if(graph[e][s])
            w=min(w,graph[e][s]);
        graph[s][e]=w;
        graph[e][s]=w;
    }
    cin>>a>>b;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.emplace(0,b);
    vector<int> visit(n+1,1e8);
    visit[b]=pq.top().first;
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        if(node==a)
            break;
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
    cout<<visit[a];

    return 0;
}
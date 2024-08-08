#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n,m,s,e,w;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        cin>>s>>e>>w;
        graph[s].emplace_back(w,e);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.emplace(0,1);
    vector<int> dist(n+1,1e8);
    dist[1]=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(int i=0;i<graph[node].size();i++){
            int ncost=graph[node][i].first;
            int nnode=graph[node][i].second;
            if(cost+ncost<dist[nnode]){
                pq.emplace(cost+ncost,nnode);
                dist[nnode]=cost+ncost;
            }
        }
    }
    for(int i=2;i<=n;i++)
        cout<<dist[i]<<"\n";
    return 0;
}
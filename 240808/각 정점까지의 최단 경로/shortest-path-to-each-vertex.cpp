#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m,k,s,e,w;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        cin>>s>>e>>w;
        graph[s].emplace_back(w,e);
        graph[e].emplace_back(w,s);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.emplace(0,k);
    vector<int> visit(n+1,1e8);
    visit[k]=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(int i=0;i<graph[node].size();i++){
            int ncost=graph[node][i].first+cost;
            int nnode=graph[node][i].second;
            if(ncost<visit[nnode]){
                visit[nnode]=ncost;
                pq.emplace(ncost,nnode);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==1e8)
            visit[i]=-1;
        cout<<visit[i]<<"\n";
    }
    return 0;
}
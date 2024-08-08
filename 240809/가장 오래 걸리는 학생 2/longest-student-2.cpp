#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n,m,s,e,w;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        cin>>s>>e>>w;
        graph[e].emplace_back(w,s);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.emplace(0,n);
    vector<int> visit(n+1,1e8);
    visit[n]=0;
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
    for(int i=0;i<=n;i++)
        if(visit[i]==1e8)
            visit[i]=-1;
    sort(visit.begin(),visit.end());
    cout<<visit[n];
    return 0;
}
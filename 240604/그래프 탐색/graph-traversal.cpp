#include <iostream>
#include <vector>
using namespace std;
int answer=0;
void dfs(int now, vector<vector<int>> &graph,vector<bool> &visit){
    for(int i=0;i<graph[now].size();i++){
        int next = graph[now][i];
        if(!visit[next]){
            answer++;
            visit[next]=true;
            dfs(next,graph,visit);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<bool> visit(n+1,false);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    visit[1]=true;
    dfs(1,graph,visit);
    cout << answer;
    return 0;
}
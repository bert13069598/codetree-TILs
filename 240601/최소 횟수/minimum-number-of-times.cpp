#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e5

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    deque<int> q;
    vector<int> visit(MAX);
    q.emplace_back(a);
    visit[a]=1;
    while(!q.empty()){ 
        int now = q.front();
        if(now==b){
            cout << visit[now]-1;
            break;
        }
        // cout << now <<"\n";
        q.pop_front();
        if(now<b){
            if(!visit[now+1] || visit[now]<visit[now+1]){
                visit[now+1]=visit[now]+1;
                q.emplace_back(now+1);
            }
        }
        if(now>0){
            if(!visit[now-1] || visit[now]<visit[now-1]){
                visit[now-1]=visit[now]+1;
                q.emplace_back(now-1);
            }
        }
        if(now<b && now*2<MAX){
            if(!visit[now*2]|| visit[now]<visit[now*2]){
                visit[now*2]=visit[now];
                q.emplace_back(now*2);
            }
        }
    }
    return 0;
}
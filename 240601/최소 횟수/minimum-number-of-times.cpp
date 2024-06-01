#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e5

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    deque<pair<int,int>> q;
    vector<bool> visit(MAX);
    q.emplace_back(a,0);
    visit[a]=true;
    while(!q.empty()){
        pair now = q.front();
        if(now.first==b){
            cout << now.second;
            break;
        }
        // cout << now.first <<"\n";
        q.pop_front();
        if(now.first<MAX && now.first<b){
            if(!visit[now.first+1]){
                visit[now.first+1]=true;
                q.emplace_back(now.first+1,now.second+1);
            }
        }
        if(now.first-1>=0){
            if(!visit[now.first-1]){
                visit[now.first-1]=true;
                q.emplace_back(now.first-1,now.second+1);
            }
        }
        if(now.first<MAX && now.first<b){
            if(!visit[now.first*2]){
                visit[now.first*2]=true;
                q.emplace_back(now.first*2,now.second);
            }
        }
    }
    return 0;
}
#include <iostream>
#include <queue>
#define MAX 1e5

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    deque<pair<int,int>> q;
    q.emplace_back(a,0);
    while(!q.empty()){
        pair now = q.front();
        if(now.first==b){
            cout << now.second;
            break;
        }
        q.pop_front();
        q.emplace_back(now.first+1,now.second+1);
        if(now.first-1>0)
            q.emplace_back(now.first-1,now.second+1);
        if(now.first*2<MAX)
            q.emplace_back(now.first*2,now.second);
    }
    return 0;
}
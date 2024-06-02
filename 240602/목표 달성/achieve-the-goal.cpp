#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    queue<pair<int,int>> q;
    q.emplace(0,0);
    int answer =1e8;
    while(!q.empty()){
        pair now = q.front();
        if(now.first==n && now.second<answer)
            answer = now.second;
        q.pop();
        if(now.first<=n){
            q.emplace(now.first+a,now.second+b);
            q.emplace(now.first+c,now.second+d);
        }
    }
    cout << answer;    
    return 0;
}
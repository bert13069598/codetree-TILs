#include <iostream>
#include <queue>

using namespace std;

int N;
int v[1000000]{};

int main() {
    cin >> N;

    int answer=0;
    queue<pair<int,int>> q;
    q.emplace(N,0);
    while(!q.empty()){
        auto [now,d]=q.front();
        q.pop();
        if(now==1){
            answer=d;
            break;
        }
        if(!v[now-1]){
            q.emplace(now-1,d+1);
            v[now-1]=true;
        }
        if(!v[now+1]){
            q.emplace(now+1,d+1);
            v[now+1]=true;
        }
        if(!v[now/2] && now%2==0){
            q.emplace(now/2,d+1);
            v[now/2]=true;
        }
        if(!v[now/3] && now%3==0){
            q.emplace(now/3,d+1);
            v[now/3]=true;
        }
    }
    cout<<answer;

    return 0;
}


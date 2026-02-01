#include <iostream>
#include <queue>

using namespace std;

int N;

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
        for(int i=0;i<4;i++){
            int next;
            if(i==0){
                q.emplace(now-1,d+1);
            }else if(i==1){
                q.emplace(now+1,d+1);
            }else if(i==2 && now%2==0){
                q.emplace(now/2,d+1);
            }else if(i==3 && now%3==0){
                q.emplace(now/3,d+1);
            }
        }
    }
    cout<<answer;

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,m;
    double w,v;
    cin>>n>>m;
    priority_queue<pair<double,int>> pq;
    for(int i=0;i<n;i++){
        cin>>w>>v;
        pq.emplace(v/w,w);
    }
    double answer=0;
    while(m>0&&!pq.empty()){
        pair now = pq.top();
        pq.pop();
        if(m>=now.second){
            answer+=now.first*now.second;
            m-=now.second;
        }else{
            answer+=now.first*m;
            m=0;
        }
    }
    cout<<fixed;
    cout.precision(3);
    cout<<answer;
    return 0;
}
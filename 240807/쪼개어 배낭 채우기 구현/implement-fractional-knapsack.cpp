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
    while(m>0){
        pair now = pq.top();
        pq.pop();
        if(now.second>0){
            m--;
            answer+=now.first;
            pq.emplace(now.first,now.second-1);
        }
    }
    cout<<fixed;
    cout.precision(3);
    cout<<answer;
    return 0;
}
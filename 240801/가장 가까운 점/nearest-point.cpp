#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int n,m,x,y;
    cin>>n>>m;
    priority_queue<tuple<int,int,int>> pq;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        pq.emplace(-x-y,-x,-y);
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        tie(a,b,c) = pq.top();
        pq.emplace(-(-b-c+4),-(-b+2),-(-c+2));
        pq.pop();
    }
    int a,b,c;
    tie(a,b,c) = pq.top();
    cout<<-b<<" "<<-c;
    return 0;
}
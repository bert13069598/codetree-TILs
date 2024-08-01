#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,m,x;
    cin>>n>>m;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }
    for(int i=0;i<m;i++){
        pq.push(pq.top()-1);
        pq.pop();
    }
    cout<<pq.top();
    return 0;
}
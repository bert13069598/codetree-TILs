#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if(a-b)
            pq.push(a-b);
    }
    if(!pq.empty())
        cout<<pq.top();
    else
        cout<<-1;
    return 0;
}
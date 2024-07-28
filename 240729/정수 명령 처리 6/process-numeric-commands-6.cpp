#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    string cmd;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>cmd;
        if(cmd=="push"){
            cin>>x;
            pq.push(x);
        }else if(cmd=="pop"){
            x=pq.top();
            pq.pop();
            cout<<x<<"\n";
        }else if(cmd=="size"){
            cout<<pq.size()<<"\n";
        }else if(cmd=="empty"){
            cout<<pq.empty()<<"\n";
        }else if(cmd=="top"){
            cout<<pq.top()<<"\n";
        }
    }

    return 0;
}
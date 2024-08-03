#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x)
            pq.push(x);
        else{
            if(!pq.empty()){
                cout<<pq.top()<<"\n";
                pq.pop();
            }else
                cout<<0<<"\n";
        }
    }
    return 0;
}
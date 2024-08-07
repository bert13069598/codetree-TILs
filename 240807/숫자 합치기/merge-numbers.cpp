#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }
    int sum=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        pq.push(a+b);
        sum+=a+b;
    }
    cout<<sum;
    return 0;
}
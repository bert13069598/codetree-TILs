#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,k,x;
    cin>>n>>k;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }
    int answer=0;
    while(k>0){
        if(k>=pq.top()){
            k-=pq.top();
            answer++;
        }
        else
            pq.pop();
    }
    cout<<answer;
    return 0;
}
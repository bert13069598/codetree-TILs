#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    int N[n];
    for(int i=0;i<n;i++)
        cin>>N[i];
    float answer=0;
    priority_queue<int> pq;
    for(int k=1;k<=n-2;k++){
        for(int i=k;i<n;i++)
            pq.push(-N[i]);
        pq.pop();
        float sum=0;
        while(!pq.empty()){
            sum+=-pq.top();
            pq.pop();
        }
        answer=max(answer,sum/(n-k-1));
    }
    cout<<fixed;
    cout.precision(2);
    cout<<answer;
    return 0;
}
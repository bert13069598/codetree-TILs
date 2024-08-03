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
    for(int k=1;k<=n-2;k++){
        priority_queue<int> pq;
        float sum=0;
        for(int i=k;i<n;i++){
            pq.push(-N[i]);
            sum+=N[i];
        }
        sum-=-pq.top();
        answer=max(answer,sum/(n-k-1));
    }
    cout<<fixed;
    cout.precision(2);
    cout<<answer;
    return 0;
}
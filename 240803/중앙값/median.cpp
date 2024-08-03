#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t,m,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m;
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        for(int j=1;j<=m;j++){
            cin>>x;
            pq1.push(x);
            pq2.push(-x);
            if(j%2)
                cout<<(pq1.top()-pq2.top())/2 <<" ";
        }
        cout<<"\n";
    }
    return 0;
}
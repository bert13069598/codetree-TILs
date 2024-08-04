#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t,m,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m;
        priority_queue<int> pqM;
        priority_queue<int> pqm;
        for(int j=1;j<=m;j++){
            cin>>x;
            if(j%2)
                pqM.push(x);
            else
                pqm.push(-x);

            if(!pqm.empty() && pqM.top()>-pqm.top()){
                int a = pqM.top();
                int b = -pqm.top();
                pqM.pop();
                pqm.pop();
                pqM.push(b);
                pqm.push(-a);
            }

            if(j%2)
                cout<<pqM.top()<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
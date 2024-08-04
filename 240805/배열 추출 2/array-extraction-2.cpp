#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    priority_queue<pair<int,bool>> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x)
            pq.emplace(-abs(x),x<0);
        else{
            if(pq.empty())
                cout<<0<<"\n";
            else{
                if(pq.top().second)
                    cout<<pq.top().first<<"\n";
                else
                    cout<<-pq.top().first<<"\n";
                pq.pop();
            }
        }
    }
    return 0;
}
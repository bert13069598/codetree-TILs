#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    deque<int> dq;
    priority_queue<int> pq;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>x;
        dq.push_back(x);
        pq.push(-x);
        sum+=x;
    }
    float answer=0;
    while(dq.size()>2){
        sum-=dq.front();
        dq.pop_front();
        while(find(dq.begin(),dq.end(),-pq.top()) == dq.end())
            pq.pop();
        // cout << sum << " " << -pq.top()<<"\n";
        answer=max(answer, (sum+pq.top())/float(dq.size()-1));
    }
    cout<<fixed;
    cout.precision(2);
    cout<<answer;
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,s,e;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        pq.emplace(e,s);
    }
    int answer=0;
    s=pq.top().first;
    e=pq.top().second;
    pq.pop();
    int ns,ne;
    while(!pq.empty()){
        ns=pq.top().first;
        ne=pq.top().second;
        pq.pop();
        if(ns>=e)
            answer++;
    }
    cout<<answer;
    return 0;
}
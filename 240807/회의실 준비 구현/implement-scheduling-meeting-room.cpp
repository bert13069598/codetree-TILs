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
    s=pq.top().second;
    e=pq.top().first;
    pq.pop();
    int ns,ne;
    while(!pq.empty()){
        ns=pq.top().second;
        ne=pq.top().first;
        pq.pop();
        if(ns>=e){
            answer++;
            s=ns;
            e=ne;
        }
    }
    cout<<answer+1;
    return 0;
}
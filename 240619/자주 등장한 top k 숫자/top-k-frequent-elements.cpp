#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> m;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
        m[nums[i]]++;
    }
    priority_queue<pair<int, int>> ans;
    for(auto &pair:m)
        ans.emplace(pair.second, pair.first);
    for(int i=0;i<k;i++){
        cout<<ans.top().second<<" ";
        ans.pop();
    }
    
    return 0;
}
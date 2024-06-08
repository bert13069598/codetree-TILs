#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> map;
    while(n--){
        int k;
        cin>>k;
        map[k]++;
    }
    while(m--){
        int k;
        cin>>k;
        cout<<map[k]<<" ";
    }
    return 0;
}
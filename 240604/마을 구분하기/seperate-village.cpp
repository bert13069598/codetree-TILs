#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum=1;
void dfs(int n,int now, int *map){
    int dxy[4]={1,-1,n,-n};
    for(int i=0;i<4;i++){
        int next=now+dxy[i];
        if(next<0||next>=n*n)
            continue;
        if(abs(dxy[i])==1 && now/n!=next/n)
            continue;
        if(map[next]){
            sum++;
            map[next]=0;
            dfs(n,next,map);
        }
    }
}

int main() {
    int n;
    cin>>n;
    int map[n*n];
    for(int i=0;i<n*n;i++)
        cin>>map[i];
    vector<int> cnt;
    for(int i=0;i<n*n;i++){
        if(map[i]){
            int now=i;
            sum=1;
            map[now]=0;
            dfs(n,now,map);
            cnt.push_back(sum);
        }
    }
    cout << cnt.size() << "\n";
    sort(cnt.begin(),cnt.end());
    for(auto p:cnt)
        cout << p << "\n";
    return 0;
}
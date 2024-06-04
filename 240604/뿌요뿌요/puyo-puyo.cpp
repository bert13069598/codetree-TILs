#include <iostream>
#include <vector>
using namespace std;

int sum=1;
void dfs(int n,int s,int now, int *map){
    int dxy[4]={1,-1,n,-n};
    for(int i=0;i<4;i++){
        int next = now + dxy[i];
        if(next<0||next>=n*n)
            continue;
        if(abs(dxy[i])==1&&now/n!=next/n)
            continue;
        if(map[next]==s){
            map[next]=0;
            sum++;
            dfs(n,s,next,map);
        }
    }
}

int main() {
    int n;
    cin>>n;
    int map[n*n];
    for(int i=0;i<n*n;i++)
        cin>>map[i];
    vector<int> block;
    for(int i=0;i<n*n;i++){
        if(map[i]!=0){
            int s = map[i];
            sum=1;
            map[i]=0;
            dfs(n, s, i,map);
            block.push_back(sum);
        }
    }
    pair<int,int> answer={0,0};
    for(auto b:block){
        if(b>=4)
            answer.first++;
        if(b>answer.second)
            answer.second = b;
    }
    cout << answer.first << " " << answer.second;
    return 0;
}
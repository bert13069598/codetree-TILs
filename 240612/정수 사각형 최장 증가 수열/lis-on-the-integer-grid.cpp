#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> map(n*n);
    vector<pair<int,int>> sortmap(n*n);
    vector<int> dp(n*n,1);
    for(int i=0;i<n*n;i++){
        int num;
        cin>>num;
        map[i]={num,i};
        sortmap[i]=map[i];
    }
    int dxy[4]={1,-1,n,-n};
    int ans=0;
    sort(sortmap.begin(),sortmap.end());
    for(int i=0;i<n*n;i++){
        int num = sortmap[i].first;
        int now = sortmap[i].second;
        for(int j=0;j<4;j++){
            int next = now + dxy[j];
            if(next<0||next>=n*n)
                continue;
            if(abs(dxy[j])==1 && now/n!=next/n)
                continue;
            if(map[next]>map[now])
                dp[next] = max(dp[next],dp[now]+1);
            if(dp[next]>ans)
                ans=dp[next];
        }

    }
    // for(int i=0;i<n*n;i++){
    //     cout<<dp[i]<<" ";
    //     if(i%n==n-1)
    //         cout<<"\n";
    // }

    cout<<ans;
    return 0;
}
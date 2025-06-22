#include <iostream>

using namespace std;

int n;

long dfs(int k){
    if(k==0||k==1)
        return 1;
    return k*dfs((k-1));
}

int main() {
    cin >> n;
    int dp[1000]={0,0,1,1,1};
    for(int i=5;i<=n;i++)
        dp[i]=(dp[i-2]+dp[i-3])%10007;
    
    cout<<dp[n];

    return 0;
}
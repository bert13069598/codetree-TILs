#include <iostream>

using namespace std;

int n,m;
int coin[100];
int dp[10001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0]=0;
    for(int i=1;i<=m;i++){
        int cost=1e6;
        for(int j=0;j<n;j++){
            if(i-coin[j]>=0)
                cost=min(cost,dp[i-coin[j]]+1);
        }
        dp[i]=cost;
    }
    for(int i=0;i<=m;i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
    
    cout<<(dp[m]==1e6 ? -1 : dp[m]);

    return 0;
}

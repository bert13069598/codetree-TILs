#include <iostream>

using namespace std;

int n;
int r[201];
int b[201];
int dp[101][101];

int main() {
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        cin >> r[i] >> b[i];
    }

    for(int i=0;i<n;i++){
        dp[0][i+1]=dp[0][i]+r[i];
        dp[i+1][0]=dp[i][0]+b[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // cout<<dp[i-1][j]<<" "<<b[i]<<" "<<dp[i][j-1]<<" "<<r[j]<<"\n";
            dp[i][j]=max(dp[i-1][j]+b[i+j-1],dp[i][j-1]+r[i+j-1]);
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<dp[n][n];

    return 0;
}

#include <iostream>

using namespace std;

int n;
int dp[100][100];
int dp0[100][100];
int dp1[100][100];
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dp[i][j];
        }
    }
    dp0[0][0]=dp[0][0];
    dp1[0][0]=dp[0][0];
    for (int i=1;i<n;i++){
        dp0[i][0]=max(dp[i][0],dp0[i-1][0]);
        dp0[0][i]=max(dp[0][i],dp0[0][i-1]);
        dp1[i][0]=min(dp[i][0],dp1[i-1][0]);
        dp1[0][i]=min(dp[0][i],dp1[0][i-1]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            int dp0a=max(dp[i][j],dp0[i-1][j]);
            int dp1a=min(dp[i][j],dp1[i-1][j]);
            int dp0b=max(dp[i][j],dp0[i][j-1]);
            int dp1b=min(dp[i][j],dp1[i][j-1]);
            if(dp0a-dp1a<dp0b-dp1b){
                dp0[i][j]=dp0a;
                dp1[i][j]=dp1a;
            }else{
                dp0[i][j]=dp0b;
                dp1[i][j]=dp1b;
            }
        }
    }

    cout<<dp0[n-1][n-1]-dp1[n-1][n-1];
    return 0;
}

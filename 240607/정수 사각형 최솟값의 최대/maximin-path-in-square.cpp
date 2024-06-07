#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int map[n][n];
    int dp[n][n];
    for(int i=0;i<n*n;i++)
        cin>>map[i/n][i%n];
    
    dp[0][0]=map[0][0];
    for(int i=0;i<n-1;i++){
        dp[0][i+1]=min(dp[0][i],map[0][i+1]);
        dp[i+1][0]=min(dp[i][0],map[i+1][0]);
    }   
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
            dp[i][j]=min(max(dp[i][j-1],dp[i-1][j]),map[i][j]);
    cout<<dp[n-1][n-1];
    return 0;
}
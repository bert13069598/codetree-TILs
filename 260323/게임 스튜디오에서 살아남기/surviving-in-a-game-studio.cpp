#include <iostream>
#include <cmath>

using namespace std;

int n;
long long dp[1001][3];

int main() {
    cin >> n;

    dp[0][0]=1;
    for(int i=0;i<n;i++){
        dp[i+1][0]=(dp[i][0]+dp[i][1]+dp[i][2])*2;
        dp[i+1][1]+=dp[i][0];
        dp[i+1][2]+=dp[i][1];
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    long long ttt=dp[n][0]+dp[n][1]+dp[n][2];
    long long bbb=pow(3,n)-(pow(2,n)+n*pow(2,n-1)+n*(n-1)/2*pow(2,n-2));

    cout<<ttt-bbb;
    return 0;
}

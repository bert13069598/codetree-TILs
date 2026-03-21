#include <iostream>

using namespace std;

int n,m;
int nums[100];
long long dp[101][41];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    dp[0][21]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<41;j++){
                dp[i+1][j+nums[i]]+=dp[i][j];
                dp[i+1][j-nums[i]]+=dp[i][j];
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<41;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<dp[n][m+21];

    return 0;
}


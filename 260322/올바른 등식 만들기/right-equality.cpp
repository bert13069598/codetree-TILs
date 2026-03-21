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

    dp[0][20]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<41;j++){
            if(abs(j+nums[i]-20)<=20)
                dp[i+1][j+nums[i]]+=dp[i][j];
            if(abs(j-nums[i]-20)<=20)
                dp[i+1][j-nums[i]]+=dp[i][j];
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<41;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<dp[n][m+20];

    return 0;
}


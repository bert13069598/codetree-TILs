#include <iostream>

using namespace std;

int n;
int lmr[1001][3];
int dp[1001][3];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> lmr[i][0] >> lmr[i][1] >> lmr[i][2];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            dp[i][j]=lmr[i][j];

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k)
                    continue;
                dp[i][j]=max(dp[i][j], lmr[i][j]+dp[i-1][k]);
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int answer=0;
    for(int i=0;i<3;i++)
        answer=max(answer,dp[n-1][i]);
    cout<<answer;

    return 0;
}

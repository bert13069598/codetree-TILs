#include <iostream>

using namespace std;

int n;
int lmr[1001][3];
int dp[3][1001][3];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> lmr[i][0] >> lmr[i][1] >> lmr[i][2];
    }

    for(int i=0;i<3;i++)
        dp[0][0][i]=lmr[0][i];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j)
                continue;
            dp[j][1][i]=lmr[1][i]+dp[0][0][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=2;j<n;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(k==l)
                        continue;
                    dp[i][j][k]=max(dp[i][j][k],lmr[j][k]+dp[i][j-1][l]);
                }
            }
        }
    }

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<n;j++){
    //         for(int k=0;k<3;k++){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    // }

    int answer=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j)
                continue;
            answer=max(answer,dp[i][n-1][j]);
        }
    }
    cout<<answer;

    return 0;
}

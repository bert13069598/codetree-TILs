#include <iostream>

using namespace std;

int n,m;
int a[501];
int dp[100][501][4];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int k=0;k<=m;k++){
        for(int i=1;i<=n;i++){
            for(int j=0;j<4;j++){
                if(i<=k)
                    continue;
                dp[k][i][j]=max(dp[k][i][j],dp[k][i-1][j]+(a[i]==j+1));
                for(int jj=0;jj<4;jj++){
                    if(j==jj)
                        continue;
                    dp[k+1][i][jj]=max(dp[k+1][i][jj],dp[k][i-1][j]+(a[i]==jj+1));
                }
            }
        }
    }

    // for(int k=0;k<=m;k++){
    //     for(int i=1;i<=n;i++){
    //         for(int j=0;j<4;j++){
    //             cout<<dp[k][i][j]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    // }

    int answer=0;
    for(int i=0;i<=m;i++)
        for(int j=0;j<4;j++)
            answer=max(answer,dp[i][n][j]);
    cout<<answer;

    return 0;
}

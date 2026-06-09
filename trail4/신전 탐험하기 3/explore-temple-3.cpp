#include <iostream>

using namespace std;

int n, m;
int a[1001][100];
int dp[1001][100];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j==k)
                    continue;
                dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][k]);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int answer=0;
    for(int j=0;j<m;j++)
        answer=max(answer,dp[n][j]);
    cout<<answer;

    return 0;
}

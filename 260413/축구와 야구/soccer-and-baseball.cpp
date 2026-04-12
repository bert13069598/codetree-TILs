#include <iostream>

using namespace std;

int n;
int s[1001];
int b[1001];
int dp[1001][12][10];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=min(k,11);i++){
            dp[k][i][0]=max(dp[k-1][i][0],dp[k-1][i-1][0]+s[k]);
        }
        for(int i=1;i<=min(k,9);i++){
            dp[k][0][i]=max(dp[k-1][0][i],dp[k-1][0][i-1]+b[k]);
        }
        for(int i=1;i<=11;i++){
            for(int j=1;j<=9;j++){
                if(i+j>k)
                    continue;
                dp[k][i][j]=max(dp[k-1][i][j-1]+b[k],dp[k-1][i-1][j]+s[k]);
                dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j]);
            }
        }
    }
    // for(int k=20;k<=20;k++){
    //    for(int i=0;i<=11;i++){
    //        for(int j=0;j<=9;j++){
    //            cout<<dp[k][i][j]<<" ";
    //        }
    //        cout<<"\n";
    //    }
    //    cout<<"\n";
    // }
    int answer=0;
    for(int i=1;i<=n;i++)
        answer=max(answer,dp[i][11][9]);
    cout<<answer;

    return 0;
}

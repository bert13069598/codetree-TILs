#include <iostream>

using namespace std;

int n, m;
string str;
int dp[21][1001];
int crystal[1001][2];

int main() {
    cin >> n >> m;
    cin >> str;
    for(int i=1;i<=n;i++)
        if(str[i-1]=='L')
            crystal[i][0]=1;
        else
            crystal[i][1]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[j][i+1]=max(dp[j][i+1],dp[j][i]+crystal[i+1][j%2]);
            if(j<m)
                dp[j+1][i+1]=dp[j][i]+crystal[i+1][(j+1)%2];
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[j][i]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int answer=0;
    for(int i=0;i<m;i++)
        answer=max(answer,dp[i][n]);
    cout<<answer;
    
    return 0;
}

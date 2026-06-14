#include <iostream>
#include <string>

using namespace std;

string A, B;
int dp[1001][1001];

int main() {
    cin >> A;
    cin >> B;

    int n=A.size();
    int m=B.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            dp[i][j]=max(dp[i][j], max(dp[i-1][j],dp[i][j-1]));
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    cout<<dp[n][m];

    return 0;
}

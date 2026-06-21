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

    bool same=false;
    for(int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][1];
        if(!same && A[i-1]==B[0])
            same=true;
        else
            dp[i][1]++;
    }
    same=false;
    for(int i=1;i<=m;i++){
        dp[1][i]=dp[1][i-1];
        if(!same && A[0]==B[i-1])
            same=true;
        else
            dp[1][i]++;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    cout<<dp[n][m];

    return 0;
}

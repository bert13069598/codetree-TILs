#include <iostream>

using namespace std;

int n, m;
int A[100];
int dp[10001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0]=0;
    fill(dp+1,dp+m+1,1e6);
    for(int i=0;i<n;i++){
        for(int j=m;j>0;j--){
            if(j-A[i]>=0){
                dp[j]=min(dp[j],dp[j-A[i]]+1);
            }
        }
    }
    // for(int i=0;i<=m;i++)
    //     cout<<dp[i]<<" ";
    // cout<<"\n";
    cout<<(dp[m]==1e6 ? -1 : dp[m]);
    return 0;
}

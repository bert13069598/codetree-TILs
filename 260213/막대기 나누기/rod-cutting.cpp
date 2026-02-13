#include <iostream>

using namespace std;

int n;
int v[100];
int dp[2][10001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=j/(i+1);k++)
                dp[i%2][j]=max(dp[i%2][j],v[i]*k+dp[(i+1)%2][j-(i+1)*k]);
            dp[i%2][j]=max(dp[i%2][j],dp[(i+1)%2][j]);
        }
        // for(int j=1;j<=n;j++)
        //     cout<<dp[i%2][j]<<" ";
        // cout<<"\n";
    }
    int answer=0;
    for(int j=1;j<=n;j++)
        answer=max(answer,dp[(n-1)%2][j]);
    cout<<answer;

    return 0;
}

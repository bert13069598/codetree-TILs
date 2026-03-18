#include <iostream>

using namespace std;

int n;
int f[1000];
int s[1000];
int dp[1001][1001];
bool v[1001][1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    v[0][0]=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]){
                v[i+1][j+1]=true;
                if(f[i]>s[j]){
                    v[i][j+1]=true;
                    dp[i][j+1]=max(dp[i][j+1],dp[i][j]+s[j]);
                }else if(f[i]<s[j]){
                    v[i+1][j]=true;
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                }
            }
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int answer=0;
    for(int i=1;i<=n;i++){
        answer=max(answer,dp[n][i]);
        answer=max(answer,dp[i][n]);
    }
    cout<<answer;

    return 0;
}

#include <iostream>

using namespace std;

int n;
int a[1001];
int dp[1001][5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int answer=0;
    if(n<=4){
        for(int i=2;i<=n;i++)
            answer+=a[i];
        cout<<answer;
        return 0;
    }
    for(int i=1;i<=4;i++){
        for(int j=i%2+1;j<=n;j+=2){
            if(i>=j)
                dp[j][i]=dp[j-1][i-1]+a[j];
            else
                dp[j][i]=max(dp[j-2][i],dp[j-1][i-1])+a[j];
        }
    }
    // for(int i=1;i<=4;i++){
    //     for(int j=1;j<=n;j++)
    //         cout<<dp[j][i]<<" ";
    //     cout<<"\n";
    // }
    for(int i=2;i<=4;i++)
        answer=max(answer,dp[n][i]);
    cout<<answer;

    return 0;
}


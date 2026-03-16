#include <iostream>

using namespace std;

int n;
int arr[100000];
int dp[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0]=arr[0];
    int answer=dp[0];
    for(int i=0;i<n-1;i++){
        if(dp[i]>=0)
            dp[i+1]=arr[i+1]+dp[i];
        else
            dp[i+1]=arr[i+1];
        answer=max(answer,dp[i+1]);
    }
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<"\n";
    cout<<answer;
    return 0;
}

#include <iostream>

using namespace std;

int N, M;
int w[100], v[100];
int dp[2][10000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i=0;i<N;i++){
        for(int j=1;j<=M;j++){
            if(j>=w[i])
                dp[i%2][j]=v[i]+dp[i%2][j-w[i]];
            dp[i%2][j]=max(dp[i%2][j],dp[(i+1)%2][j]);
        }
        // for(int j=1;j<=M;j++){
        //     cout<<dp[i%2][j]<<" ";
        // }cout<<"\n";
    }
    int answer=0;
    for(int j=1;j<=M;j++)
        answer=max(answer,dp[(N-1)%2][j]);
    cout<<answer;
    

    return 0;
}

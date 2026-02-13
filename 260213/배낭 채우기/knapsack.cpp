#include <iostream>

using namespace std;

int N, M;
int w[100], v[100];
int dp[2][10001];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i=0;i<N;i++){
        for(int j=1;j<=M;j++){
            if(j-w[i]>=0)
                dp[i%2][j]=max(dp[(i+1)%2][j],v[i]+dp[(i+1)%2][j-w[i]]);
            else
                dp[i%2][j]=dp[(i+1)%2][j];
        }
        // for(int j=1;j<=M;j++)
        //     cout<<dp[i%2][j]<<" ";
        // cout<<"\n";
    }
    int answer=0;
    for(int i=1;i<=M;i++)
        answer=max(answer,dp[(N-1)%2][i]);
    cout<<answer;

    return 0;
}

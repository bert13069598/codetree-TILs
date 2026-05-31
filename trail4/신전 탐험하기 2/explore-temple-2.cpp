#include <iostream>

using namespace std;

int n;
int lmr[1001][3];
int dp[1001][3];
int fi[1001][3];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> lmr[i][0] >> lmr[i][1] >> lmr[i][2];
    }

    for(int i=0;i<3;i++){
        dp[0][i]=lmr[0][i];
        fi[0][i]=i;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            int prev=0;
            for(int k=0;k<3;k++){
                if(j==k)
                    continue;
                if(i==n-1 && j==fi[i-1][k])
                    continue;
                if(dp[i-1][k]>prev){
                    prev=dp[i-1][k];
                    fi[i][j]=fi[i-1][k];
                }
            }
            dp[i][j]=lmr[i][j]+prev;
        }
    }

    int answer=0;
    for(int i=0;i<3;i++){
        answer=max(answer,dp[n-1][i]);
    }
    cout<<answer;

    return 0;
}

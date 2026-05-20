#include <iostream>

using namespace std;

int n;
int dp[1000][10];

int main() {
    cin >> n;

    for(int i=1;i<10;i++)
        dp[0][i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            if(j==0)
                dp[i][j]=dp[i-1][j+1];
            else if(j==9)
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
        }
    }

    int answer=0;
    for(int i=0;i<10;i++)
        answer+=dp[n-1][i];
    cout<<answer;

    return 0;
}

#include <iostream>

using namespace std;

int n;
int l[1001], m[1001], r[1001];
int dp[1001][3];
int fi[1001][3];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }

    dp[0][0]=l[0];
    fi[0][0]=0;
    dp[0][1]=m[0];
    fi[0][1]=1;
    dp[0][2]=r[0];
    fi[0][2]=2;

    for(int i=1;i<n;i++){
        dp[i][0]=l[i]+max(m[i-1],r[i-1]);
        fi[i][0]=m[i-1]>r[i-1] ? fi[i-1][1] : fi[i-1][2]; 
        dp[i][1]=m[i]+max(l[i-1],r[i-1]);
        fi[i][1]=l[i-1]>r[i-1] ? fi[i-1][0] : fi[i-1][2]; 
        dp[i][2]=r[i]+max(l[i-1],m[i-1]);
        fi[i][2]=l[i-1]>m[i-1] ? fi[i-1][1] : fi[i-1][1]; 
    }
    int answer=0;
    for(int i=0;i<3;i++){
        if(fi[n-1][i]==fi[0][i])
            dp[n-1][i]=0;
        answer=max(answer,dp[n-1][i]);
    }
    cout<<answer;

    return 0;
}

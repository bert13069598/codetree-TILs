#include <iostream>

using namespace std;

int n, m;
int e[100], t[100];
bool dp0[100000001];
int dp[100000001];

int main() {
    cin >> n >> m;
    int sum=0;
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
        sum+=e[i];
    }
    dp0[0]=true;
    for(int i=0;i<n;i++){
        for(int j=sum;j>=1;j--){
            if(j-e[i]>=0 && dp0[j-e[i]]){
                if(dp0[j])
                    dp[j]=min(dp[j],t[i]+dp[j-e[i]]);
                else
                    dp[j]=t[i]+dp[j-e[i]];
                dp0[j]=true;
            }
        }
    }
    // for(int g=m;g<=sum;g++)
    //     cout<<dp[g]<<" ";
    // cout<<"\n";

    int answer=1e8;
    for(int i=m;i<=sum;i++)
        if(dp[i])
            answer=min(answer,dp[i]);
    cout<<(answer==1e8?-1:answer);

    return 0;
}

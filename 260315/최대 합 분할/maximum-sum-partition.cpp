#include <iostream>

using namespace std;

int n;
int arr[100];
int dp[100001];
int group[100001][100];

int main() {
    cin >> n;
    int suma=0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        suma+=arr[i];
    }
    int groupa=suma/2;

    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=groupa;j>=1;j--){
            if(j-arr[i]>=0 && dp[j-arr[i]]){
                dp[j]++;
                group[i][j]=dp[j];
                for(int k=0;k<n;k++){
                    if(group[k][j-arr[i]] && group[k][j]==0)
                        group[k][j]=dp[j];
                }
            }
        }
    }
    int answer=0;
    for(int i=1;i<=groupa;i++){
        if(dp[i]!=2)
            continue;
        int sum=0;
        for(int j=0;j<n;j++){
            if(group[j][i]==1)
                sum+=arr[j];
            else if(group[j][i]==2)
                sum-=arr[j];
        }
        if(sum==0)
            answer=max(answer,i);
    }

    // cout<<"\n";
    // for(int i=0;i<n;i++){
    //     for(int j=1;j<=groupa;j++){
    //         cout<<group[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<answer;

    return 0;
}

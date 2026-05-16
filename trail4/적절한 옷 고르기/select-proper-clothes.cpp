#include <iostream>

using namespace std;

int N, M;
int s[200], e[200], v[200];
int arr[200][200];
int dp[200][200];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }
    for (int i = 0; i < N; i++) {
        for(int j=s[i]-1;j<=e[i]-1;j++)
            arr[i][j]=1;
    }
    // for (int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++)
    //         cout<<arr[i][j]<<" ";
    //     cout<<"\n";
    // }

    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(!arr[j][i])
                continue;
            int maxi=0,maxv=0;
            for(int k=0;k<N;k++){
                if(j!=k && arr[k][i-1]){
                    int diff=abs(v[j]-v[k]);
                    if(diff>maxv){
                        maxi=k;
                        maxv=diff;
                    }
                }
            }
            dp[j][i]=dp[maxi][i-1]+maxv;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    int answer=0;
    for(int i=0;i<N;i++)
        answer=max(answer,dp[i][M-1]);
    cout<<answer;    

    return 0;
}

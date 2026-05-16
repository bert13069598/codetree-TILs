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
            int maxv=0;
            for(int k=0;k<N;k++){
                if(j!=k && arr[k][i-1]){
                    maxv=max(maxv,dp[k][i-1]+abs(v[j]-v[k]));
                }
            }
            dp[j][i]=maxv;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    int answer=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            answer=max(answer,dp[i][j]);
    cout<<answer;    

    return 0;
}

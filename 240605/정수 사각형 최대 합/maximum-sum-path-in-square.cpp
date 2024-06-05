#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int map[n][n];
    int sub[n][n];
    for(int i=0;i<n*n;i++){
        cin>>map[i/n][i%n];
        sub[i/n][i%n]=map[i/n][i%n];
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<n-1){
                map[i][j+1]=max(sub[i][j+1]+map[i][j],map[i][j+1]);
                answer=max(answer,map[i][j+1]);
            }
            if(i<n-1){
                map[i+1][j]+=map[i][j];
                answer=max(answer,map[i+1][j]);
            }
        }
    }
    // for(int i=0;i<n*n;i++){
    //     cout<<map[i/n][i%n]<<"\t";
    //     if(i%n==n-1)
    //         cout<<"\n";
    // }

    cout << answer;
    return 0;
}
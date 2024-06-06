#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int map[n][n];
    int sub[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            sub[i][j]=map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(i<n-1){
                map[i+1][j]+=map[i][j];
            }
            if(j){
                if(i)
                    map[i][j-1]=min(map[i][j-1],sub[i][j-1]+map[i][j]);
                else
                    map[i][j-1]=map[i][j-1]+map[i][j];
            }
        }
    }
    cout<<map[n-1][0];
    return 0;
}
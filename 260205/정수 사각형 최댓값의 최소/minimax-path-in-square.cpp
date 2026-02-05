#include <iostream>

using namespace std;

int n;
int grid[100][100];
int a[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    a[0][0]=grid[0][0];
    for(int i=0;i<n-1;i++){
        a[i+1][0]=max(a[i][0],grid[i+1][0]);
        a[0][i+1]=max(a[0][i],grid[0][i+1]);
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1;j++)
            a[i+1][j+1]=max(min(a[i+1][j],a[i][j+1]),grid[i+1][j+1]);
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<a[n-1][n-1];    

    return 0;
}

#include <iostream>

using namespace std;

int n, m;
int grid[50][50];
int a[50][50];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            for(int p=i+1;p<n;p++){
                for(int q=j+1;q<n;q++){
                    if(grid[p][q]>grid[i][j])
                        a[p][q]=max(a[p][q],a[i][j]+1);
                }
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout<<"\n";
    // }

    int answer=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            answer=max(answer, a[i][j]);
    cout<<answer+1;

    return 0;
}

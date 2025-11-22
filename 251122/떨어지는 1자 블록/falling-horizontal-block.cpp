#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;
    k--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int x=-1,nx=-1;
    while(x==nx){
        nx=x+1;
        int j=k;
        for(;j<k+m;j++)
            if(grid[nx][j]==1)
                break;
        if(j==k+m)
            x=nx;
        else
            for(int j=k;j<k+m;j++)
                grid[x][j]=1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

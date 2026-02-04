#include <iostream>

using namespace std;

int n;
int grid[100][100];
pair<int,int> a[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    a[0][0]=make_pair(grid[0][0],grid[0][0]);
    for(int i=0;i<n-1;i++){
        a[i+1][0]=make_pair(min(a[i][0].first,grid[i+1][0]), max(a[i][0].second,grid[i+1][0]));
        a[0][i+1]=make_pair(min(a[0][i].first,grid[0][i+1]), max(a[0][i].second,grid[0][i+1]));
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            auto &l=a[i+1][j], &r=a[i][j+1];
            int next=grid[i+1][j+1];
            int l_diff=max(l.second, next) - min(l.first, next);
            int r_diff=max(r.second, next) - min(r.first, next);
            if(l_diff>r_diff)
                a[i+1][j+1]=make_pair(min(r.first, next), max(r.second, next));
            else
                a[i+1][j+1]=make_pair(min(l.first, next), max(l.second, next));
            // a[i+1][j+1]=make_pair(min(max(a[i][j+1].first,a[i+1][j].first), grid[i+1][j+1]),
            //                       max(min(a[i][j+1].second,a[i+1][j].second), grid[i+1][j+1]));
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<a[i][j].first<<","<<a[i][j].second<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<a[n-1][n-1].second-a[n-1][n-1].first;

    return 0;
}

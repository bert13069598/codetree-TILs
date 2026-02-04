#include <iostream>

using namespace std;

int n;
int grid[100][100];
pair<int,int> a[100][100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    a[0][0][0]=make_pair(grid[0][0],grid[0][0]);
    for(int i=0;i<n-1;i++){
        a[0][i+1][0]=make_pair(min(a[0][i][0].first,grid[i+1][0]), max(a[0][i][0].second,grid[i+1][0]));
        a[0][0][i+1]=make_pair(min(a[0][0][i].first,grid[0][i+1]), max(a[0][0][i].second,grid[0][i+1]));
    }

    int m=1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            bool issame=false;
            for(int k=0;k<m;k++){
                auto &l=(a[k][i+1][j].first==0) ? a[0][i+1][j] : a[k][i+1][j];
                auto &r=(a[k][i+1][j].first==0) ? a[0][i][j+1] : a[k][i][j+1];
                int next=grid[i+1][j+1];
                int r_diff=max(r.second, next) - min(r.first, next);
                int l_diff=max(l.second, next) - min(l.first, next);
                if(l_diff>r_diff)
                    a[k][i+1][j+1]=make_pair(min(r.first, next), max(r.second, next));
                else if(l_diff<r_diff)
                    a[k][i+1][j+1]=make_pair(min(l.first, next), max(l.second, next));
                else{
                    if(l.first==r.first && l.second==r.second)
                        a[k][i+1][j+1]=make_pair(min(r.first, next), max(r.second, next));
                    else{
                        // r
                        a[k][i+1][j+1]=make_pair(min(r.first, next), max(r.second, next));
                        // l
                        a[k+1][i+1][j+1]=make_pair(min(l.first, next), max(l.second, next));
                        issame=true;
                    }
                }
            }
            if(issame)
                m++;
        }
    }

    // for(int k=0;k<m;k++){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             cout<<a[k][i][j].first<<","<<a[k][i][j].second<<" ";
    //         }
    //         cout<<"\n";
    //     }
    // cout<<"\n";
    // }

    int answer=100;
    for(int i=0;i<m;i++)
        answer=min(answer,a[i][n-1][n-1].second-a[i][n-1][n-1].first);
    cout<<answer;

    return 0;
}

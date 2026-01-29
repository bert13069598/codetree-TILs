#include <iostream>

using namespace std;

int n;
int grid[10][10];
int v[10]{};
int answer=0;

void dfs(int now){
    if(n==now){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=grid[i][v[i]];
        answer=max(answer,sum);
        return;
    }
    for(int i=0;i<n;i++){
        if(v[now])
            continue;
        v[now]=i;
        dfs(now+1);
        v[i]=0;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(0);
    cout<<answer;

    return 0;
}

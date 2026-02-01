#include <iostream>

using namespace std;

int n;
int grid[10][10];
int idx[10];
bool v[10]{};
int answer=0;

void dfs(int now){
    if(n==now){
        int num=1e4;
        for(int i=0;i<n;i++)
            num=min(num,grid[i][idx[i]]);
        answer=max(answer,num);
    }
    for(int i=0;i<n;i++){
        if(v[i])
            continue;
        idx[now]=i;
        v[i]=true;
        dfs(now+1);
        v[i]=false;
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

#include <iostream>

using namespace std;

int n;
int grid[10][10];
int num[10];
bool v[10];
int answer=0;

void dfs(int now){
    if(n==now){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=grid[i][num[i]];
        answer=max(answer,sum);
        return;
    }
    for(int i=0;i<n;i++){
        if(v[i])
            continue;
        num[now]=i;
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

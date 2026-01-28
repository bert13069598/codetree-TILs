#include <iostream>

using namespace std;

int n, m;
int A[20];
int num[20];
int answer=0;

void dfs(int now){
    if(m==now){
        int ret=num[0];
        for(int i=1;i<m;i++)
            ret^=num[i];
        answer=max(answer,ret);
        return;
    }
    for(int i=0;i<n;i++){
        num[now]=A[i];
        dfs(now+1);
        num[now]=0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dfs(0);
    cout<<answer;

    return 0;
}
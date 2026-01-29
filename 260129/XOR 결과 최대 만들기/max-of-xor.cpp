#include <iostream>

using namespace std;

int n, m;
int A[20];
int idx[20];
int answer=0;

void dfs(int now){
    if(m==now){
        int ret=0;
        for(int i=0;i<m;i++)
            ret^=A[idx[i]];
        answer=max(answer,ret);
        return;
    }
    for(int i=now;i<n;i++){
        if(i>0 && idx[now-1]>=i)
            continue;
        idx[now]=i;
        dfs(now+1);
        idx[now]=0;
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
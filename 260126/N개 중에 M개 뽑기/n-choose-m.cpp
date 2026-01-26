#include <iostream>

using namespace std;

int N, M;
int num[10];

void dfs(int now){
    if(now==M){
        for(int i=0;i<M;i++)
            cout<<num[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<N;i++){
        if(now>0 && num[now-1]>=i+1)
            continue;            
        num[now]=i+1;
        dfs(now+1);
        num[now]=0;
    }
}

int main() {
    cin >> N >> M;

    dfs(0);

    return 0;
}


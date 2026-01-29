#include <iostream>

using namespace std;

int n;
int num[8];
bool v[8]{};

void dfs(int now){
    if(n==now){
        for(int i=0;i<n;i++)
            cout<<n-num[i]<<" ";
        cout<<"\n";
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

    dfs(0);

    return 0;
}


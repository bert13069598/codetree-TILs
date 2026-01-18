#include <iostream>

using namespace std;

int n;
int x1[15], x2[15];
int v[15]{};
int answer=0;

void dfs(int now,int d){
    // for(int i=1;i<d;i++)
    //     cout<<" ";
    // cout<<now<<"\n";
    answer=max(answer,d);
    if(d==n)
        return;
    for(int next=now;next<n;next++){
        if(v[next]==0){
            if((x1[now]<=x2[next])^(x2[now]>=x1[next])){
                v[next]=1;
                dfs(next,d+1);
                v[next]=0;
            }
        }
    }
    return; 
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for(int now=0;now<n;now++){
        v[now]=1;
        dfs(now,1);
        v[now]=0;
        // cout<<"\n";
    }
    cout<<answer;
    return 0;
}

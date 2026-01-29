#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int x[20], y[20];
int i1[20], i2[2];
int answer=1e5;

int dfs2(int now){
    if(2==now){
        // for(int i=0;i<2;i++)
        //     cout<<i1[i];
        // cout<<" ";
        // for(int i=0;i<2;i++)
        //     cout<<i2[i];
        // cout<<"\n";
        return pow(x[i1[i2[0]]]-x[i1[i2[1]]],2) + pow(y[i1[i2[0]]]-y[i1[i2[1]]],2);
    }
    int dist=0;
    for(int i=now;i<m;i++){
        if(i>0 && i2[now-1]>=i)
            continue;
        i2[now]=i;
        dist=max(dist,dfs2(now+1));
    }
    return dist;
}

void dfs1(int now){
    if(m==now){
        // for(int i=0;i<m;i++)
        //     cout<<i1[i];
        // cout<<"\n";
        answer=min(answer,dfs2(0));
        return;
    }
    for(int i=now;i<n;i++){
        if(i>0 && i1[now-1]>=i)
            continue;
        i1[now]=i;
        dfs1(now+1);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    dfs1(0);
    cout<<answer;

    return 0;
}

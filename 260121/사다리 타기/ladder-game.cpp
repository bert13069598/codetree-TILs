#include <iostream>

using namespace std;

int n, m;
int a[15], b[15];
int critic[11];
int ladder[11][15];  // N M
int answer=0;

int ride(int now){
    for(int i=0;i<15;i++){
        if(now && ladder[now-1][i])
            now--;
        else if(ladder[now][i])
            now++;
    }
    return now;
}

void dfs(int now,int d){
    // for(int i=0;i<d;i++)
    //     cout<<" ";
    // cout<<now<<"\n";
    bool issame=true;
    for(int i=0;i<n;i++)
        if(critic[i]!=ride(i))
            issame=false;
    if(issame)
        answer=min(answer,d+1);

    if(d==m-2)
        return;
    for(int next=now+1;next<m;next++){
        ladder[a[next]-1][b[next]-1]=1;
        dfs(next,d+1);
        ladder[a[next]-1][b[next]-1]=0;
    }
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    // make critic
    for(int i=0;i<m;i++)
        ladder[a[i]-1][b[i]-1]=1;
    for(int i=0;i<n;i++)
        critic[i]=ride(i);
    // for(int i=0;i<n;i++)
    //     cout<<critic[i]<<" ";

    // when nothing is best
    bool issame=true;
    for(int i=0;i<n;i++)
        if(critic[i]!=i)
            issame=false;
    if(issame){
        cout<<answer;
        return 0;
    }else{
        for(int i=0;i<m;i++)
           ladder[a[i]-1][b[i]-1]=0;
    }

    answer=m;
    for(int i=0;i<n;i++){
        ladder[a[i]-1][b[i]-1]=1;
        dfs(i,0);
        ladder[a[i]-1][b[i]-1]=0;
    }

    cout<<answer;

    return 0;
}

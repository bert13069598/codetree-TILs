#include <iostream>

using namespace std;

int n;
int A[10][10];
pair<int,int> idx[10];
bool v[10]{};
int answer=1e5;

void dfs(int now){
    if(n==now){
        int sum=0;
        for(int i=0;i<n;i++){
            // cout<<idx[i].first<<" "<<idx[i].second<<"\n";
            sum+=A[idx[i].first][idx[i].second];
        }
        // cout<<sum<<"\n";
        // cout<<"\n";
        answer=min(answer,sum);
        return;
    }
    if(0==now){
        for(int j=1;j<n;j++){
            if(!A[0][j])
                continue;
            idx[now]=make_pair(0,j);
            v[j]=true;
            dfs(now+1);
            v[j]=false;
        }
    }else if(n-1==now){
        int i=idx[now-1].second;
        if(A[i][0]){
            idx[now]=make_pair(i,0);
            dfs(now+1);
        }
    }else{
        int i=idx[now-1].second;
        for(int j=1;j<n;j++){
            if(!A[i][j] || v[j])
                continue;
            idx[now]=make_pair(i,j);
            v[j]=true;
            dfs(now+1);
            v[j]=false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    dfs(0);
    cout<<answer;

    return 0;
}

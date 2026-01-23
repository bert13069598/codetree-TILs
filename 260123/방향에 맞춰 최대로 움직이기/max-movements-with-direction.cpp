#include <iostream>
#include <queue>

using namespace std;

int n;
int num[4*4];
int dirs[4*4];
int dx[8]={-1,-1,0,1,1, 1, 0,-1};
int dy[8]={ 0, 1,1,1,0,-1,-1,-1};
int r, c;
int answer=0;

void dfs(int now,int d){
    queue<int> q;
    int dir=dirs[now];
    int tmp=now;
    while(true){
        int next=tmp+dx[dir]*n+dy[dir];
        if(next>=n*n || next<0)
            break;
        if(dx[dir]*dy[dir]==0 && tmp/n!=next/n)
            break;
        if(num[next]>num[now]){
            q.emplace(next);
        }
        tmp=next;
    }
    while(!q.empty()){
        dfs(q.front(),d+1);
        q.pop();
    }
    answer=max(answer,d);
}

int main() {
    cin >> n;

    for (int i = 0; i < n*n; i++)
        cin >> num[i];

    for (int i = 0; i < n*n; i++){
        cin >> dirs[i];
        dirs[i]--;
    }

    cin >> r >> c;
    r--;
    c--;
    dfs(r*n+c,1);

    cout<<answer;

    return 0;
}

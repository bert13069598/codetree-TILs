#include <iostream>

using namespace std;

int n;
int x1[16], x2[16];

int dfs(int now,int depth){
    // cout<<depth<<" "<<now<<" "<<x1[now]<<" "<<x2[now]<<"\n";
    if(depth==n)
        return depth;
    int next=now+1;
    if((x2[now]>=x1[next]) == (x1[now]<=x2[next]))
        return depth;
    int answer=0;
    for(int i=now;i<=n;i++){
        answer=max(answer,dfs(next,depth+1));
        if(answer==n)
            break;
    }
    return answer;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x1[i] >> x2[i];
    }

    int answer=0;
    for(int i=1;i<=n;i++){
        answer=max(answer,dfs(i,1));
        if (answer==n)
            break;
    }
    cout<<answer;

    return 0;
}

#include <iostream>

using namespace std;

int n, m, k;
int nums[12];
int player[4]={1,1,1,1};
int answer=0;

void dfs(int now){
    if(now==n){
        int score=0;
        for(int i=0;i<k;i++)
            if(player[i]==m)
                score++;
        answer=max(answer,score);
        return;
    }
    for(int i=0;i<k;i++){
        if(player[i]+nums[now]<=m){
            player[i]+=nums[now];
            dfs(now+1);
            player[i]-=nums[now];
        }else{
            int tmp=player[i];
            player[i]=m;
            dfs(now+1);
            player[i]=tmp;
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    dfs(0);
    cout<<answer;
    return 0;
}

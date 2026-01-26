#include <iostream>

using namespace std;

int n;
int num[10];

int dfs(int now,int d){
    if(now==n-1)
        return d;
    int answer=10;
    for(int i=0;i<num[now];i++){
        int next=now+i+1;
        if(next==n)
            break;
        answer=min(answer,dfs(next,d+1));
    }
    if(answer==10)
        answer=-1;
    return answer;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout<<dfs(0,0);
    return 0;
}

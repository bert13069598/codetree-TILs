#include <iostream>

using namespace std;

int n;
int num[20];
int pick[10];
int answer=1e4;

void dfs(int now){
    if(n==now){
        bool ab[20]{};
        for(int i=0;i<n;i++)
            ab[pick[i]]=true;
        int d=0;
        for(int i=0;i<2*n;i++)
            if(ab[i])
                d+=num[i];
            else
                d-=num[i];
        answer=min(answer,abs(d));
        return;
    }
    for(int i=now;i<2*n;i++){
        if(i>0 && pick[now-1]>=i)
            continue;
        pick[now]=i;
        dfs(now+1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }

    dfs(0);
    cout<<answer;

    return 0;
}

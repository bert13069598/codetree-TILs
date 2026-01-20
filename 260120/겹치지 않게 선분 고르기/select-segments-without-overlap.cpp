#include <iostream>

using namespace std;

int n;
int x1[15], x2[15];
bool v[15];
int answer=0;

void dfs(int now,int d){
    // for(int i=1;i<d;i++)
    //     cout<<" ";
    // cout<<now<<"\n";
    answer=max(answer,d);
    if(d==n)
        return;
    for(int next=now+1;next<n;next++){
        bool isol=false;
        for(int prev=0;prev<now;prev++){
            if((x1[prev]<=x2[now])==(x2[now]>=x1[next])){
                isol=true;
                break;
            }
        }
        if(!isol && ((x1[now]<=x2[next])^(x2[now]>=x1[next]))){
            dfs(next,d+1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }
    
    if(n==1)
        answer=1;
    else{
        for(int now=0;now<n-1;now++)
            dfs(now,1);
    }
    
    cout << answer;

    return 0;
}

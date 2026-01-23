#include <iostream>

using namespace std;

int n,m;
int num[80];
bool running=true;

bool dfs2(int now){
    if((m+1)/2==now)
        return true;
    bool isol=true;
    for(int i=0;i<=now;i++)
        if(num[m-i]!=num[m-i-now-1])
            isol=false;
    bool answer=false;
    if(!isol)
        answer=dfs2(now+1);
    return answer;
}

void dfs1(int now){
    if(n==now){
        for(int i=0;i<n;i++)
            cout<<num[i];
        cout<<"\n";
        running=false;
        return;
    }
    for(int i=4;i<7;i++){
        if(!running)
            break;
        num[now]=i;
        m=now;

        // for(int i=0;i<n;i++)
        //     cout<<num[i];
        // cout<<" "<<dfs2(0)<<"\n";
        if(dfs2(0))
            dfs1(now+1);
        num[now]=0;
    }
}

int main() {
    cin >> n;

    dfs1(0);

    return 0;
}

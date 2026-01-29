#include <iostream>
#include <algorithm>

using namespace std;

int n, s, e, j=0;
pair<int,int> coin[20*20];
int pick[3];
int answer=20*20;

int get_dist(int s,int e){
    return abs(s/n-e/n) + abs(s%n-e%n);
}

void dfs(int now){
    if(3==now){
        int d=get_dist(e,coin[pick[0]].second);
        d+=get_dist(coin[pick[0]].second,coin[pick[1]].second);
        d+=get_dist(coin[pick[1]].second,coin[pick[2]].second);
        d+=get_dist(coin[pick[2]].second,s);
        answer=min(answer,d);
    }
    for(int i=now;i<j;i++){
        if(i>0 && pick[now-1]>=i)
            continue;
        pick[now]=i;
        dfs(now+1);
        pick[now]=0;
    }
}

int main() {
    cin >> n;
    char c;
    for(int i=0;i<n*n;i++){
        cin>>c;
        if(c=='S')
            s=i;
        else if(c=='E')
            e=i;
        else if(c=='.'){}
        else
            coin[j++]=make_pair(c-'0',i);
    }
    if(j<3){
        cout<<-1;
        return 0;
    }
    sort(coin, coin+j, greater<>());
    dfs(0);
    cout<<answer;

    return 0;
}

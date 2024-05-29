#include <iostream>
#include <vector>
using namespace std;
int K,r,c;
int answer=0;
void dfs(int a,int b,vector<int> &map){
    int dxy[4]={1,-1,5,-5};
    for(int i=0;i<4;i++){
        int na=a+dxy[i];
        if(na<0||na>=25)
            continue;
        if(abs(dxy[i])==1 && na/5!=a/5)
            continue;
        if(!map[na]){
            map[na]=map[a]+1;
            if(map[na]+map[b]==25-K){
            // for(int i=0;i<25;i++){
            //     cout << map[i] << " ";
            //     if(i%5==5-1)
            //         cout<<"\n";
            // }cout <<"\n";
                answer++;
                return;
            }
            for(int j=0;j<4;j++){
                int nb=b+dxy[j];
                if(nb<0||nb>=25)
                    continue;
                if(abs(dxy[j])==1 && nb/5!=b/5)
                    continue;
                if(!map[nb]){
                    map[nb]=map[b]+1;
                    dfs(na,nb,map);
                    map[nb]=0;
                }
            }
            map[na]=0;
        }
    }
}

int main() {
    vector<int> map(25);
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>r>>c;
        r--;
        c--;
        map[r*5+c]=1;
    }
    map[0]=1;
    map[24]=1;
    dfs(0,25-1,map);

    cout << answer;
    return 0;
}
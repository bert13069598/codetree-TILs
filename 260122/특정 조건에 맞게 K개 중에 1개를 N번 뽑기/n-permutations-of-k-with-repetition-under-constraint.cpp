#include <iostream>

using namespace std;

int K, N;
int num[8]{};

void dfs(int now){
    if(now==N){
        for(int i=0;i<N;i++)
            cout<<num[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<K;i++){
        if(now>1){
            bool istriple=true;
            if(i+1!=num[now-1])
                istriple=false;
            if(num[now-1]!=num[now-2])
                istriple=false;
            if(!istriple){
                num[now]=i+1;
                dfs(now+1);
            }
        }else{
            num[now]=i+1;
            dfs(now+1);
        }
    }
    return;
}

int main() {
    cin >> K >> N;

    dfs(0);

    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int map[n*n];
    for(int i=0;i<n*n;i++)
        cin>>map[i];
    int dxy[4]={1,n,-1,-n};
    int answer=0;
    for(int now=0;now<n*n;now++){
        int side = 0;
        for(int j=0;j<4;j++){
            int next = now+dxy[now];
            if(next<0||next>=n*n)
                continue;
            if(abs(dxy[j])==1 && now/n != next/n)
                continue;
            if(map[next]==1)
                side++;
        }
        if(side>=3)
            answer++;
    }
    cout<< answer;

    return 0;
}
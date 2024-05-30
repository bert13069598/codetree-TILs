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
    for(int i=0;i<n*n;i++){
        int side = 0;
        for(int j=0;j<4;j++){
            int next = i+dxy[i];
            if(next<0||next>=n*n)
                continue;
            if(abs(dxy[i])==1 && i/n != next/n)
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
#include <iostream>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;
int grid[100*100];

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;

    for(int i=0;i<n*n;i++)
        grid[i]=0;
    
    int dxy[8]={n+2,2*n+1,2*n-1,n-2,-n-2,-2*n-1,-2*n+1,-n+2};
    
    queue<int> q;
    q.push(r1*n+c1);
    while(!q.empty()){
        int now=q.front();
        if(now==r2*n+c2){
            cout<<grid[now];
            return 0;
        }
        q.pop();
        for(int i=0;i<8;i++){
            int next=now+dxy[i];
            if(next<0||next>=n*n)
                continue;
            if((i==0||i==3||i==4||i==7) && abs(now/n-next/n)!=1)
                continue;
            if((i==1||i==2||i==5||i==6) && abs(now/n-next/n)!=2)
                continue;
            if(grid[next]==0){
                grid[next]=grid[now]+1;
                q.push(next);
            }
        }
    }
    cout<<-1;

    return 0;
}

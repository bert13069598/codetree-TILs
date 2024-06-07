#include <iostream>
using namespace std;

bool win=false;
void dfs2(int n, int now, int *map,int team,int i,int d){
    if(d==5)
        win=true;
    else if(d>5)
        win=false;
    int dxy[8]={1,-1,n,-n,n+1,n-1,-n+1,-n-1};
    int next=now+dxy[i];
    if(next<0||next>=n*n)
        return;
    if(abs(dxy[i])==1&&now/n!=next/n)
        return;
    if(map[next]==team){
        dfs2(n,next,map,team,i,d+1);
    }
}

void dfs(int n,int now, int *map,int team){
    int dxy[8]={1,-1,n,-n,n+1,n-1,-n+1,-n-1};
    for(int i=0;i<8;i++){
        int next=now+dxy[i];
        if(next<0||next>=n*n)
            continue;
        if(abs(dxy[i])==1&&now/n!=next/n)
            continue;
        if(map[next]==team){
            dfs2(n,next,map,team,i,2);
        }
    }
}

int main() {
    int n=19;
    int map_[n*n];
    int map[n*n];
    for(int i=0;i<n*n;i++)
        cin>>map_[i];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            map[j*n+i]=map_[i*n+j];
    }

    int team = 0;
    pair<int,int> xy;
    for(int i=0;i<n*n;i++){
        if(map[i]==1 || map[i]==2){
            win=false;
            team=map[i];
            xy={i/n+1,i%n+1};

            dfs(n,i,map,team);
            if(win){
                if(team==1)
                    cout << 1 << "\n";
                else if(team==2)
                    cout << 2 << "\n";
                cout << xy.second << " " << xy.first;
                return 0;
            }
        }
    }
    cout << 0 << "\n";;
    return 0;
}
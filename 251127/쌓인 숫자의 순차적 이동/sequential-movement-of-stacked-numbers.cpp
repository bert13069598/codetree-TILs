#include <iostream>
#include <deque>

using namespace std;

int n, m;
deque<int> grid[20*20];
int pg[20*20];  // pos grid
int mg[20*20];  // max grid
int num;

int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,1,-1,1,-1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n*n; i++) {
        cin >> num;
        pg[num]=i;
        mg[i]=num;
        grid[i].emplace_back(num);
    }

    for (int i = 0; i < m; i++) {
        cin >> num;
        int x=pg[num]/n;
        int y=pg[num]%n;
        int mx,my,mc=0;
        for(int j=0;j<8;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if((unsigned)nx>=n||(unsigned)ny>=n)
                continue;
            if(mg[nx*n+ny]>mc){
                mx=nx;
                my=ny;
                mc=mg[nx*n+ny];
            }
        }
        if(mc==0)
            continue;
        deque<int> tmp;
        int now=x*n+y;
        int next=mx*n+my;
        while(!grid[now].empty()){
            int c=grid[now].back();
            tmp.emplace_front(c);
            grid[now].pop_back();
            if(c==num)
                break;
        }
        while(!tmp.empty()){
            int c=tmp.front();
            pg[c]=next;
            mg[next]=max(mg[next],c);
            grid[next].emplace_back(c);
            tmp.pop_front();
        }
        mg[now]=0;
        while(!grid[now].empty()){
            int c=grid[now].front();
            mg[now]=max(mg[now], c);
            tmp.emplace_back(c);
            grid[now].pop_front();
        }
        while(!tmp.empty()){
            grid[now].emplace_back(tmp.front());
            tmp.pop_front();
        }
    }

    for (int i = 0; i < n*n; i++) {
        if(grid[i].empty())
            cout<<"None\n";
        else{
            while(!grid[i].empty()){
                num=grid[i].back();
                grid[i].pop_back();
                cout<<num<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

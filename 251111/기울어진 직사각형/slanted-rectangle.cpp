#include <iostream>

using namespace std;

int n;
int grid[20][20];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int dx[4]={-1,-1,1,1};
    int dy[4]={1,-1,-1,1};

    int answer=0;
    for(int i=1;i<n-1;i++){
        int x=n-1;
        int y=i;
        int sum=0;
        for(int j=0;j<4;j++){
            while(true){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if((unsigned)nx>=n||(unsigned)ny>=n)
                    break;
                sum+=grid[nx][ny];
                x=nx;
                y=ny;
            }
        }
        answer=max(answer,sum);
    }

    cout<<answer;

    return 0;
}

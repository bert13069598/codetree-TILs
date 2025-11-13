#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int f(int x,int y,int h,int w){
    int sum=0;
    for(int i=x;i<h;i++){
        for(int j=y;j<w;j++){
            if(grid[i][j]>0)
                sum++;
            else
                return -1;
        }
    }
    return sum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=-1;
    
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int h=1;h<=n-i;h++){
                for(int w=1;w<=m-j;w++){
                    int sum=f(i,j,i+h,j+w);
                    if (sum>0)
                        answer=max(answer,sum);
                }
            }
        }
    }
    
    cout<<answer;

    return 0;
}

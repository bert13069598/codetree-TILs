#include <iostream>

using namespace std;

int grid[4][4];
char dir;

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;
    if(dir=='L'){
        for(int i=0;i<4;i++){
            int temp[4]{},k=0;
            for(int j=0;j<4;j++)
                if(grid[i][j]>0)
                    temp[k++]=grid[i][j];
            for(int j=0;j<3;j++){
                if(temp[j]==temp[j+1]){
                    temp[j]*=2;
                    temp[j+1]=0;
                }
            }
            k=0;
            for(int j=0;j<4;j++){
                if(temp[j]>0)
                    grid[i][k++]=temp[j];
            }
            for(int j=k;j<4;j++)
                grid[i][j]=0;
        }
    }else if(dir=='R'){
        for(int i=0;i<4;i++){
            int temp[4]{},k=0;
            for(int j=3;j>=0;j--)
                if(grid[i][j]>0)
                    temp[k++]=grid[i][j];
            for(int j=0;j<3;j++){
                if(temp[j]==temp[j+1]){
                    temp[j]*=2;
                    temp[j+1]=0;
                }
            }
            k=3;
            for(int j=0;j<4;j++){
                if(temp[j]>0)
                    grid[i][k--]=temp[j];
            }
            for(int j=k;j>=0;j--)
                grid[i][j]=0;
        }
    }else if(dir=='U'){
        int temp[4]{},k=0;
        for(int j=0;j<4;j++)
            if(grid[j][i]>0)
                temp[k++]=grid[j][i];
        for(int j=0;j<3;j++){
            if(temp[j]==temp[j+1]){
                temp[j]*=2;
                temp[j+1]=0;
            }
        }
        k=0;
        for(int j=0;j<4;j++){
            if(temp[j]>0)
                grid[k++][i]=temp[j];
        }
        for(int j=k;j<4;j++)
            grid[j][i]=0;
    }else if(dir=='D'){
            int temp[4]{},k=0;
            for(int j=3;j>=0;j--)
                if(grid[j][i]>0)
                    temp[k++]=grid[j][i];
            for(int j=0;j<3;j++){
                if(temp[j]==temp[j+1]){
                    temp[j]*=2;
                    temp[j+1]=0;
                }
            }
            k=3;
            for(int j=0;j<4;j++){
                if(temp[j]>0)
                    grid[k--][i]=temp[j];
            }
            for(int j=k;j>=0;j--)
                grid[j][i]=0;
    }


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout<<"\n";
    }

    return 0;
}

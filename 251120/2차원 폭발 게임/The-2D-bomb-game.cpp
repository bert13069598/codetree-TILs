#include <iostream>

using namespace std;

int n,m,k;
int a[100][100];

void bomb(){
    for(int j=0;j<n;j++){
        int sum=1;
        for(int i=0;i<n-1;i++){
            if(a[i][j]==a[i+1][j]){
                sum++;
            }else{
                if(sum>=m){
                    int x=i;
                    while(sum--)
                        a[x--][j]=0;
                }
                sum=1;
            }
        }
        if(sum>=m){
            int x=n-1;
            while(sum--)
                a[x--][j]=0;
        }
    }
}

void fall(){
    for(int j=0;j<n;j++){
        int temp[n]{},k=0;
        for(int i=n-1;i>=0;i--)
            if(a[i][j])
                temp[k++]=a[i][j];
        for(int i=n-1;i>=0;i--)
            a[i][j]=temp[n-1-i];
    }
}

void rotate(){
    int temp[n][n]{};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            temp[j][-i+n-1]=a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            a[i][j]=temp[i][j];
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while(k--){
        bomb();
        fall();
        rotate();
        fall();
    }
    bomb();

    int answer=0;
    for(int i=0;i<n*n;i++)
        if(a[i/n][i%n])
            answer++;

    cout<<answer;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << " ";
    //     }cout << "\n";
    // }

    return 0;
}

#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

void wave(int r,bool left){
    int temp;
    if(left)
        temp=a[r][m-1];
    else
        temp=a[r][0];
    for(int i=0;i<m-1;i++)
        if(left)
            a[r][m-1-i]=a[r][m-1-i-1];
        else
            a[r][i]=a[r][i+1];
    if(left)
        a[r][0]=temp;
    else
        a[r][m-1]=temp;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while(q--){
        int r;
        char d;
        cin >> r >> d;
        r--;
        bool d1=d=='L', d2=d=='L';
        wave(r,d=='L');
        int up=r-1;
        int down=r+1;
        for(int i=up;i>=0;i--){
            bool same=false;
            for(int j=0;j<m;j++){
                if(a[i+1][j]==a[i][j]){
                    same=true;
                    break;
                }
            }
            if(same){
                d1=!d1;
                wave(i,d1);
            } else
                break;
        }
        for(int i=down;i<n;i++){
            bool same=false;
            for(int j=0;j<m;j++){
                if(a[i-1][j]==a[i][j]){
                    same=true;
                    break;
                }
            }
            if(same){
                d2=!d2;
                wave(i,d2);
            } else
                break;     
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

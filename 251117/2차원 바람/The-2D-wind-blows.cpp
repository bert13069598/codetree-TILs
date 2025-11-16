#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void f(int r1,int c1,int r2,int c2){
    int temp=a[r1][c1];
    for(int i=r1;i<r2;i++)
        a[i][c1]=a[i+1][c1];
    for(int i=c1;i<c2;i++)
        a[r2][i]=a[r2][i+1];
    for(int i=r2;i>r1;i--)
        a[i][c2]=a[i-1][c2];
    for(int i=c2;i>c1;i--)
        a[r1][i]=a[r1][i-1];
    a[r1][c1+1]=temp;

    int mean[100][100]{};
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            float num=1;
            float sum=a[i][j];
            for(int t=0;t<4;t++){
                int ni=i+dx[t];
                int nj=j+dy[t];
                if((unsigned)ni>=n||(unsigned)nj>=m)
                    continue;
                num++;
                sum+=a[ni][nj];
            }
            mean[i][j]=(int)(sum/num);
        }
    }
    for(int i=r1;i<=r2;i++)
        for(int j=c1;j<=c2;j++)
            a[i][j]=mean[i][j];
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        f(r1,c1,r2,c2);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) 
            cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

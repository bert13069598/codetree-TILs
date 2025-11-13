#include <iostream>

using namespace std;

int n, t;
int lrd[600];

int main() {
    cin >> n >> t;

    for (int i = 0; i < 3*n; i++) cin >> lrd[i];

    for(int i=0;i<t;i++){
        int temp=lrd[3*n-1];
        for(int i=0;i<3*n;i++)
            lrd[3*n-1-i]=lrd[3*n-1-i-1];
        lrd[0]=temp;
    }

    for (int i = 0; i < 3*n; i++){
        cout<<lrd[i]<<" ";
        if(i%n==n-1)
            cout<<"\n";
    }
    return 0;
}

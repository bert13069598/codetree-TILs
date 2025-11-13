#include <iostream>

using namespace std;

int n, t;
int u[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i=0;i<t;i++){
        int temp[2] = {u[n-1],d[n-1]};
        for(int i=0;i<n-1;i++){
            u[n-1-i]=u[n-1-i-1];
            d[n-1-i]=d[n-1-i-1];
        }
        u[0]=temp[1];
        d[0]=temp[0];
    }
    
    for (int i = 0; i < n; i++) cout << u[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << d[i] << " ";

    return 0;
}

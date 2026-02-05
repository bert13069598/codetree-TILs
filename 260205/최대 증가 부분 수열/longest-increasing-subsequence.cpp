#include <iostream>

using namespace std;

int n;
int M[1000];
int a[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }

    a[0]=1;
    for(int i=0;i<n-1;i++){
        if(M[i+1]>M[i])
            a[i+1]=a[i]+1;
        else
            a[i+1]=a[i];
    }
    cout<<a[n-1];

    return 0;
}

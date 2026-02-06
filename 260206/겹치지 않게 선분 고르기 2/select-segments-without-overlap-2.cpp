#include <iostream>

using namespace std;

int n;
int x1[1000];
int x2[1000];
int a[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if((x1[i]<x2[j]) == (x2[i]<x1[j]))
                a[j]=max(a[j],a[i]+1);
    
    int answer=0;
    for(int i=0;i<n;i++)
        answer=max(answer,a[i]);
    cout<<answer+1;

    return 0;
}

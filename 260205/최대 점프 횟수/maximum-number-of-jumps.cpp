#include <iostream>

using namespace std;

int n;
int arr[1000];
int a[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    a[0]=1;
    int last=0;
    for(int i=0;i<n-1;i++){
        if(!a[i])
            continue;
        last=i;
        for(int j=i+1;j<min(n,i+1+arr[i]);j++){
            if(arr[j]){
                a[j]=max(a[j],a[i]+1);
                last=j;
            }
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout<<"\n";

    // cout<<last<<"\n";
    cout<<(last==n-1 ? a[last]-1 : a[last]);
    return 0;
}
